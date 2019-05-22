# 　　　　　　git实用命令
1. 将工作区和缓冲区的内容全部清除，并退到最近的commit内容

   `git reset --hard HEAD^`


2. 提交错误

+ 不小心错误提交一个commit A到github，但是你想提交的是commit B:

   首先`git reset --hard HEAD^`，本地退回到上一个版本

   然后修改好commit B，本地提交后，`git push --force`，就可以把github上的commit A删掉，变成commit B。

   注意：`git push --force`可能需要相应分支的权限，有一定风险性，注意备份.

+ 本地提交了，还没有push到github，需要修改log

  直接`git commit --amend`，会跳出写log的界面，直接修改即可

3. 
