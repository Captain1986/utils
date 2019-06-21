# 　　　　　　Anaconda使用经验

1. 换回默认源

  `conda config --remove-key channels`

2. 建立一个新的环境

  `conda create --name py352 python=3.5.2`

   按照yml文件的配置建立一个新的环境

  `conda env create -f environment.yml`

   按照yml更新现有环境

  `conda env update -f environment.yml`

3. 删除一个新的环境（然后选择y）

  `conda create --name py352 python=3.5.2`

   或者

  `conda remove -n py352 --all`

4. 切换到一个已有的环境

  `conda activate py352`

5. 退出当前环境

  `conda deactivate`

6. 查看已有环境列表

  `conda info -e`

7. 添加镜像源（Anaconda的清华TUNA镜像）

  `conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/`

  `conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/`

  `conda config --set show_channel_urls yes`

8. 查看已经安装在本环境中的包

  `conda list`

9. 查找可安装的包（pandas为例）

  `conda search pandas`

10. 安装包

  `conda install pandas`

11. 更新包

  `conda update pandas`

12. 卸载包

  `conda remove pandas`

13.

