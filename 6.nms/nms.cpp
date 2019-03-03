#include <iostream>

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
 * 参考资料：https://zhuanlan.zhihu.com/p/49481833， https://zhuanlan.zhihu.com/p/50126479，https://zhuanlan.zhihu.com/p/42018282
 * */

std::vector<int> nms(const std::vector<std::vector<float>> boxes, const float threshold, const std::string type)
{
    if (boxes.empty()) {
        return pick;
    }

    int n = 0;
    std::vector<int> list_k(boxes.size());
    std::generate(std::begin(list_k), std::end(list_k), [&] { return n++; });
    // 以分数由低到高排列
    std::sort(list_k.begin(), list_k.end(),
              [&](int i1, int i2) { return boxes[i1][4] < boxes[i2][4]; });

    std::vector<int> pick;
    while (!list_k.empty()) {
        // 保留本轮最高分的index
        int top_1 = list_k[list_k.size() - 1];
		pick.push_back(top_1);

		for(int i = 0; i < list_k.size() - 2; i++) {
			if(iou(boxes, lisk_k[i], top_1) > threshold) {
			   DELETE list_k[i];
			}
		}
    }

    return pick;
}

