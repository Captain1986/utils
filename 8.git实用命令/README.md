# 　　　　　　git实用命令
1. 不小心错误提交一个commit A到github，但是你想提交的是commit B:

   首先git reset --hard HEAD^，本地退回到上一个版本

   然后修改好commit B，本地提交后，git push --force，就可以把github上的commit A删掉，变成commit B。

   注意：git push --force可能需要相应分支的权限，有一定风险性，注意备份

2. 