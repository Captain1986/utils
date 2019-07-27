# 　　　　　　Anaconda使用经验

1. 关闭默认进去base环境

  `conda config --set auto_activate_base false`

2. 换回默认源

  `conda config --remove-key channels`

3. 建立一个新的环境

  `conda create --name py352 python=3.5.2`

   按照yml文件的配置建立一个新的环境

  `conda env create -f environment.yml`

   按照yml更新现有环境

  `conda env update -f environment.yml`

4. 删除一个新的环境（然后选择y）

  `conda create --name py352 python=3.5.2`

   或者

  `conda remove -n py352 --all`

5. 切换到一个已有的环境

  `conda activate py352`

6. 退出当前环境

  `conda deactivate`

7. 查看已有环境列表

  `conda info -e`

8. 添加镜像源（Anaconda的清华TUNA镜像）

  `conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/`

  `conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/`

  `conda config --set show_channel_urls yes`

9. 查看已经安装在本环境中的包

  `conda list`

10. 查找可安装的包（pandas为例）

  `conda search pandas`

11. 安装包

  `conda install pandas`

12. 更新包

  `conda update pandas`

13. 卸载包

  `conda remove pandas`

14.

