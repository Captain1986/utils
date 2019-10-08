# 　　　　　　git实用命令

1. 将工作区和缓冲区的内容**全部清除**，并退到最近的commit内容

​     `git reset --hard HEAD^`

2. **提交错误**

+ 不小心错误提交一个commit A到GitHub，但是你想提交的是commit B:

  首先`git reset --hard HEAD^`，本地退回到上一个版本

  然后修改好commit B，本地提交后，`git push --force`，就可以把GitHub上的commit A删掉，变成commit B。

  注意：`git push --force`可能需要相应分支的权限，有一定风险性，注意备份.

+ 本地提交了，还没有push到GitHub，需要修改log

  直接`git commit --amend`，会跳出写log的界面，直接修改即可

+ 本地提交了，也push到GitHub了，需要修改上次提交（例如追加一个漏掉的文件）

  `git commit -m 'initial commit'`

  `git add forgotten_file`

  `git commit --amend`

  `git push --force`

3. 你正在某个开发分支工作，但是master分支需要紧急做一个hotfix，可以用git stash**保存当前工作进度**，去master上做完了再切回来继续你的工作

​     `git stash`

​     `git checkout master`

​      *working on master branch*

​     `git checkout dev`

​     `git stash pop`

4. 删除远程分支

​     `git push origin --delete [branchname]`

## 参考文献

[Git菜单](https://geeeeeeeeek.github.io/git-recipes/)

[gitmoji](https://gitmoji.carloscuesta.me/)

