# Git

## 1. 设置用户

1. 不等于登录，仅告知远程仓库是谁上传的
2. 命令行
   - `git config --global user.name "XiaoLinZeng`
   - `git config --global user.email "zxl13825648558@outlook.com`
   

## 2. 本地文件

### 2.1 进入文件夹

- Way1: 直接在电脑上找到相应文件夹，打开后在空白处右键选择Git Bash here

- Way2: 在GIt Bash中输入路径

  如进入`C:\Users\XiaoLinZeng\Git`

  - 逐个输入: "cd c", "cd users", "cd XiaoLinZeng", "cd Git"
  - 一次性输入: "cd c/Users/XiaoLinZeng/Git" (**是斜线不是反斜线**)



### 2.2 查看

1. 查看当前目录: `pwd`
2. 查看当前文件夹中的文件: `ls`



### 2.3 退出文件夹

`cd ..`



### 2.4 新建和删除

1. `mkdir+文件夹名称`(**只能新建文件夹**)
2. `touch+文件名称`(只能新建**文件**)
3. `rm+文件名.文件类型`(**删除**文件, 注意要返回**上一级**)



## 3. 仓库设置

### 3.1 初始化本地仓库

- 使用当前目录作为git仓库, 只需将其初始化`git init`

- `git init newrepo`, 初始化后, 在newrepo目录下出现一个名为.git的目录

### 3.2 在github上建立远程仓库



### 3.3 建立连接

#### 3.3.1 建立远程仓库和本地仓库的链接

1. 配置SSH
2. 使用SSH连接
3. 在本地仓库打开git bash
   `git remote add + 仓库名称 + 链接地址`



#### 3.3.2 git remote命令

用于管理Git中的远程仓库, 包括查看, 添加, 重命名, 删除功能

- `git remote`：列出当前仓库中已配置的远程仓库。
- `git remote -v`：列出当前仓库中已配置的远程仓库，并显示它们的 URL。
- `git remote add <remote_name> <remote_url>`：**添加一个新的远程仓库**。指定一个远程仓库的名称和 URL，将其添加到当前仓库中。
- `git remote rename <old_name> <new_name>`：将已配置的**远程仓库重命名**。
- `git remote remove <remote_name>`：**从当前仓库中删除**指定的远程仓库。



#### 3.3.3 配置





### 3.4 文件上传和克隆

#### 3.4.1 git add

将修改的文件添加**暂存**区

- `git add +文件名.文件类型` ，将某个文件加到缓存区

- `git add -u` ，提交被修改和被删除文件，不包括新文件
- `git add .`，提交新文件和被修改文件，不包括被删除文件

- **git add -A**，提交**所有变化**



#### 3.4.2 git commit

将当前暂存区的文件**实际保存**到仓库的历史记录中

- `git commit -m "在此处添加注释`<br>

  

#### 3.4.3 git push

- 向仓库中推文件: `git push 仓库名称 分支`(只有主分支时填master)

- 只有第一次推文件的时候需要加上**-u**, 即: `git push 仓库名称 分支`



#### 3.4.4其他

- 如何修改commit的注释？
  `$ git commit --amend -m "修改的内容"`

- 如何修改文件名?

  修改文件名后重新提交即可 (??)

  

#### 3.5 文件克隆

自己的仓库可以使用SSH, 别人的要用HTTPS, 先复制地址, 然后打卡打算放入的文件夹, 在此处打开git bash

- `git clone 刚才复制的地址`
- 克隆后使用`git remote -v`命令查看本地仓库是否与远程仓库连接成功