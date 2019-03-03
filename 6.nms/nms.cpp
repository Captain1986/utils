#include <vector>
#include <string>
#include <algorithm>

// 坐标系和OpenCV保持一致，左上角为原点，X轴从左到右，Y轴从上到下
float iou(const std::vector<float> boxA, const std::vector<float> boxB)
{
    const float x11 = boxA[0];// 第一个box左上角点的X坐标
    const float y11 = boxA[1];// 第一个box左上角点的Y坐标
    const float x12 = boxA[2];// 第一个box右下角点的X坐标
    const float y12 = boxA[3];// 第一个box右下角点的Y坐标
    const float Aarea = (y12 - y11 + 1) * (x12 - x11 + 1);

    const float x21 = boxB[0];
    const float y21 = boxB[1];
    const float x22 = boxB[2];
    const float y22 = boxB[3];
    const float Barea = (y22 - y21 + 1) * (x22 - x21 + 1);

    const float interX1 = std::max(x11, x21);
    const float interY1 = std::max(y11, y21);
    const float interX2 = std::min(x12, x22);
    const float interY2 = std::min(y12, y22);

    const float interArea = std::max(0.0f, interY2 - interY1 + 1) * std::max(0.0f, interX2 - interX1 + 1);

    return interArea / (Aarea + Barea - interArea);
}

/*
 * 非极大值抑制NMS(non-maximum suppression)是目标检测中常见的去重方案
 * 这里是一种C++实现，需要支持C++11的编译器编译
 *
 * boxes，输入，原始框信息组成的向量，其中每个元素都是一个原始框的信息，
 *        这些信息依次以x_topleft,y_topleft,x_bottomright,ybuttomright,confidence为顺序
 * threshold，输入，置信度阈值，仅保留置信度大于它的原始框
 * type， 输入，nms类型，normal表示用常见的nms，soft表示用soft nms，默认normal
 * 输出：nms算法的返回值，是一个向量，向量中的每一个元素表示保留下来的原始框在输入boxes中的下标
 *       如果输入boxes空，则返回为空
 *
 * 参考资料：https://zhuanlan.zhihu.com/p/49481833， https://zhuanlan.zhihu.com/p/50126479，https://zhuanlan.zhihu.com/p/42018282
 * */

std::vector<int> nms(const std::vector<std::vector<float>> boxes, const float threshold/*, const std::string type*/)
{
    if (boxes.empty()) {
        return std::vector<int>();
    }

    std::vector<int> list_k(boxes.size());
    int n = 0;
    std::generate(std::begin(list_k), std::end(list_k), [&] { return n++; });
    // 以分数由低到高排列
    std::sort(list_k.begin(), list_k.end(),
              [&](int i1, int i2) { return boxes[i1][4] < boxes[i2][4]; });

    std::vector<int> pick;
    while (!list_k.empty()) {
        // 保留本轮最高分的index
        const int top_1 = list_k.back();
        pick.push_back(top_1);

        // 删除最高分的index
        list_k.pop_back();

        for(auto it = list_k.begin(); it != list_k.end(); NULL/*在循环内自增*/) {
            if(iou(boxes[*it], boxes[top_1]) > threshold) {
               it = list_k.erase(it);
            } else {
               ++it;
            }
        }
    }

    return pick;
}

