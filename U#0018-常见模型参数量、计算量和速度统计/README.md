# 　　　　　　常见模型参数量、计算量和速度统计

**本文总结常见模型参数量、计算量和速度信息备查**

## 目录

[1. 分类网络](# 分类网络)

[2.目标检测网络](# 目标检测网络)

[3.关键点检测网络](# 关键点检测网络)

[4. 参考资料](# 参考资料)

### 分类网络

|        Model        | Input Resolution | Params(M) | MACs(GFLOPS) | Acc@1  | Acc@5  |
| :-----------------: | :--------------: | :-------: | :----------: | :----: | ------ |
|       AlexNet       |     224x224      |   61.10   |     0.72     | 56.432 | 79.194 |
|      GoogLeNet      |     224x224      |   7.00    |     1.60     |        |        |
|        VGG11        |     224x224      |  132.86   |     7.63     | 69.02  | 88.63  |
|      VGG11_bn       |     224x224      |  132.87   |     7.64     | 70.38  | 89.81  |
|        VGG13        |     224x224      |  133.05   |    11.34     | 69.93  | 89.25  |
|      VGG13_bn       |     224x224      |  133.05   |    11.36     | 71.55  | 90.37  |
|        VGG16        |     224x224      |  138.36   |     15.5     | 71.59  | 90.38  |
|      VGG16_bn       |     224x224      |  138.37   |    15.53     | 73.37  | 91.50  |
|        VGG19        |     224x224      |  143.67   |    19.67     | 72.38  | 90.88  |
|      VGG19_bn       |     224x224      |  143.68   |    19.70     | 74.24  | 91.85  |
|      ResNet18       |     224x224      |   11.69   |     1.82     | 69.76  | 91.08  |
|      ResNet34       |     224x224      |   21.80   |     3.68     | 73.30  | 91.42  |
|      ResNet50       |     224x224      |   25.56   |     4.12     | 76.15  | 92.87  |
|   Wide_ResNet50_2   |                  |   68.88   |    11.46     |        |        |
|      ResNet101      |     224x224      |   44.55   |     7.85     | 77.37  | 93.56  |
|  Wide_ResNet101_2   |                  |  126.89   |    22.84     |        |        |
|      ResNet152      |     224x224      |   60.19   |    11.58     | 78.31  | 94.06  |
|    SqueezeNet1_0    |     224x224      |   1.25    |     0.83     | 58.10  | 80.42  |
|    SqueezeNet1_1    |     224x224      |   1.24    |     0.36     | 58.19  | 80.62  |
|     DenseNet121     |     224x224      |   7.98    |     2.88     | 74.65  | 92.17  |
|     DenseNet161     |     224x224      |   28.68   |     7.82     | 77.65  | 93.80  |
|     DenseNet169     |     224x224      |   14.15   |     3.42     | 76.00  | 93.00  |
|     DenseNet201     |     224x224      |   20.01   |     4.37     | 77.20  | 93.57  |
|    Inception_v3     |     224x224      |   27.16   |     2.85     | 77.45  | 93.56  |
|    Inception_v3     |     299x299      |   27.16   |     5.73     | 77.294 | 93.454 |
|    Inception_v4     |     299x299      |   42.68   |    13.31     | 80.062 | 94.926 |
|    Inception_bn     |     224x224      |   11.3    |     2.05     | 73.524 | 91.562 |
|       DPN107        |     224x224      |   86.92   |    18.42     | 79.746 | 94.684 |
|       DPN131        |     224x224      |   79.25   |    16.13     | 79.432 | 94.574 |
|        DPN68        |     224x224      |   12.61   |     2.36     | 75.868 | 92.774 |
|       DPN68b        |     224x224      |   12.61   |     2.36     | 77.034 | 93.59  |
|        DPN92        |     224x224      |   37.67   |     6.56     |  79.4  | 94.62  |
|        DPN98        |     224x224      |   61.57   |    11.76     | 79.224 | 94.488 |
|     FBResNet152     |     224x224      |   60.27   |     11.6     | 77.386 | 93.594 |
|  InceptionResNetv2  |     299x299      |   55.84   |    13.22     | 80.17  | 95.234 |
|    NasNetaLarge     |     331x331      |   88.75   |    24.04     | 82.566 | 96.086 |
|    NasNetaMobile    |     224x224      |   5.29    |     0.59     | 74.08  | 91.74  |
|    Pnasnet5Large    |     331x331      |   86.06   |    25.21     | 82.736 | 95.992 |
|       PolyNet       |     331x331      |   95.37   |    34.90     | 81.002 | 95.624 |
|   ResNeXt50_32x4d   |                  |   25.03   |     4.29     |        |        |
|  ResNeXt101_32x4d   |     224x224      |   44.18   |     8.03     | 78.188 | 93.886 |
|  ResNeXt101_32x8d   |                  |   88.79   |    16.54     |        |        |
|  ResNeXt101_64x4d   |     224x224      |   83.46   |    15.55     | 78.956 | 94.252 |
|    se_ResNet101     |     224x224      |   49.33   |     7.63     | 78.396 | 94.258 |
|    se_ResNet152     |     224x224      |   66.82   |    11.37     | 78.658 | 94.374 |
|     se_ResNet50     |     224x224      |   28.09   |     3.9      | 77.636 | 93.752 |
| se_ResNeXt101_32x4d |     224x224      |   48.96   |     8.05     | 80.236 | 95.028 |
| se_ResNeXt50_32x4d  |     224x224      |   27.56   |     4.28     | 79.076 | 94.434 |
|      SENet154       |     224x224      |  115.09   |    20.82     | 81.304 | 95.498 |
|      Xception       |     299x299      |   22.86   |     8.42     | 78.888 | 94.292 |
|       TextCNN       |                  |   0.15    |    0.009     |        |        |
|     MnasNet0_5      |                  |   2.22    |     0.14     |        |        |
|     MnasNet0_75     |                  |   3.17    |     0.24     |        |        |
|     MnasNet1_0      |                  |   4.38    |     0.34     |        |        |
|     MnasNet1_3      |                  |   6.28    |     0.53     |        |        |
|    MobileNet_v2     |                  |   3.50    |     0.33     |        |        |
| Shufflenet_v2_x0_5  |                  |   1.37    |     0.05     |        |        |
| Shufflenet_v2_x1_0  |                  |   2.28    |     0.15     |        |        |
| Shufflenet_v2_x1_5  |                  |   3.50    |     0.31     |        |        |
| Shufflenet_v2_x2_0  |                  |   7.39    |     0.60     |        |        |

### 目标检测网络

|          Model          | Input Resolution | Params Memory | Feature Memory |   FLOPS    |
| :---------------------: | :--------------: | :-----------: | :------------: | :--------: |
|    RFCN-Res50-Pascal    |     600x850      |    122 MB     |      1 GB      | 79 GFLOPS  |
|   RFCN-Res101-Pascal    |     600x850      |    194 MB     |      2 GB      | 117 GFLOPS |
|  SSD-Pascal-VGGvd-300   |     300x300      |    100 MB     |     116 MB     | 31 GFLOPS  |
|  SSD-Pascal-VGGvd-512   |     512x512      |    104 MB     |     337 MB     | 91 GFLOPS  |
| SSD-Pascal-MobileNet-ft |     300x300      |     22 MB     |     37 MB      |  1 GFLOPS  |
| FasterRCNN-VGGvd-Pascal |     600x850      |    523 MB     |     600 MB     | 172 GFLOPS |

### 分割网络

|       Model       | Input Resolution | Params Memory | Feature Memory |   FLOPS    |
| :---------------: | :--------------: | :-----------: | :------------: | :--------: |
|  Pascal-FCN-32s   |     384x384      |    519 MB     |     423 MB     | 125 GFLOPS |
|  Pascal-FCN-16s   |     384x384      |    514 MB     |     424 MB     | 125 GFLOPS |
|   Pascal-FCN-8s   |     384x384      |    513 MB     |     426 MB     | 125 GFLOPS |
| Deeplab-VGGvd-v2  |     513x513      |    144 MB     |     755 MB     | 202 GFLOPS |
| Deeplab-Res101-v2 |     513x513      |    505 MB     |      4 GB      | 346 GFLOPS |

### 关键点检测网络

|     Model      | Input Resolution | Params Memory | Feature Memory |   FLOPS    |
| :------------: | :--------------: | :-----------: | :------------: | :--------: |
| MultiPose-mpi  |     368x368      |    196 MB     |     245 MB     | 134 GFLOPS |
| MultiPose-coco |     368x368      |    200 MB     |     246 MB     | 136 GFLOPS |

### 参考资料

[pytorch-OpCounter](https://github.com/Lyken17/pytorch-OpCounter)

[flops-counter.pytorch](https://github.com/sovrasov/flops-counter.pytorch)

[convnet-burden](https://github.com/albanie/convnet-burden)

[Characterization and Benchmarking of Deep Learning](https://www.hpcuserforum.com/presentations/Wisconsin2017/HPDLCookbook4HPCUserForum.pdf)

