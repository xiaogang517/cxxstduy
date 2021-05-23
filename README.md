# cxxstduy

#当前所在目录，使用如下命令查看
pwd

#列出当前目录所有文件和文件夹
ls
ls -al



#切换目录 第一种cd是绝对路径（当前路径可以是任何路径）；第二种路径是相对路径(只能在当前路径为/home/betterfish时使用)
cd /home/betterfish/cxxstduy
cd cxxstduy

#新建一个目录，比如名字为myfolder  （新建时注意查看pwd）
mkdir myfloder

#删除一个目录myfolder
rm -r myfloder

#新建一个my.cpp文件
touch my.cpp

#删除一个my.cpp文件
rm my.cpp

#如果一个文件（或则目录）已经被git管理，删除的话请用
git rm my.cpp

#将修改过的（或者新建的）文件/目录添加到git
git add myfloder

#撤销
git reset myfloder

#恢复上一个提交的状态
git checkout myfloder

#查看修改的内容
git diff HEAD
git diff my.cpp

#查看目前git的状态：
git status -s

#若状态无误，提交为
git commit -m "your message"

#推送到github网站
git push

#拷贝一个仓库 
git clone https://github.com/xiaogang517/cxxstduy.git

#若仓库已经拷贝，但该仓库有更新没有被同步（比如另外一个用户提交了新的内容上去）
git pull
