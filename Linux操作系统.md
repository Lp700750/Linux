## Linux操作系统

#### 1.*Linux操作系统的基础知识*

- 作为一款开源软件，*Linux*与其他的操作系统相比较具有效率更高，稳定性更好，更加的安全，并且还是免费的
- 由于具有上述的诸多好处，*Linux*是企业服务器的首选操作系统
- *Linux*的版本组成
  - 内核版本：各种各样的内核版本，他是Linux操作系统的真正核心组成部分
  - 发行版本：它是由*Linux*内核和应用层服务组成，常见的有*Ubuntu Kali Debian Redhat Centos*等发行版本

- 操作系统的作用(**相当于管家也可以说是一种桥梁**)
  - 对于用户来说：给用户提供一个良好的运行环境
  - 对于硬件来说：通过指令管理各类硬件

![alt](D:\PostgaduateStudies\编程资料\C++资料\博客文档\Linux操作系统\操作系统所处的位置.png)

#### 2.*Linux*常见的操作指令

**1.常见指令的使用**

- *Linux*显示的都是文件  **文件=内容+属性**
- <font color='red'>***d***</font>:文件的类型是目录   <font color='red'>**-**</font>：文件的类型是普通的文件
- 在*Linux*当中，以 <font color='red'>**.**</font> 开头的的文件是隐藏文件

```C++
d rwxrwxr-x 2 Jolly.Roger Jolly.Roger 4096 Aug  6 15:07 .    //当前路径
d rwx------ 5 Jolly.Roger Jolly.Roger 4096 Aug  6 14:47 ..   //上级路径
- rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug  6 15:07 a.out
- rw-rw-r-- 1 Jolly.Roger Jolly.Roger   70 Aug  6 15:06 test1.c
```

- 大部分的操作系统，组织文件的基本结构是一颗多叉树

**2.*cd*的使用**

- *cat*能够查看文件里面的内容
- *cd*只能够查看目录里面的文件(当前的目录之下)
- *cd*能够查看其文件的方法
  - 如果是当前的目录之下，就可以直接加上*cd* 文件名进入或者是*cd./*文件名
  - 如果是其他目录之下，则需要使用相对路径或者是绝对路径才能够进行访问
- *cd~*进入到工作目录当中
  - 如果是用户，就会进入到用户的工作目录
  - 如果是管理员，就会进入到/root下

```C++
[Jolly.Roger@VM-16-9-centos lesson3]$ cd file1
[Jolly.Roger@VM-16-9-centos file1]$ pwd
/home/Jolly.Roger/lesson3/file1
[Jolly.Roger@VM-16-9-centos file1]$ cd ..
[Jolly.Roger@VM-16-9-centos lesson3]$ cd ./file1
[Jolly.Roger@VM-16-9-centos file1]$ pwd
/home/Jolly.Roger/lesson3/file1
```

```C++
[Jolly.Roger@VM-16-9-centos lesson3]$ pwd
/home/Jolly.Roger/lesson3
[Jolly.Roger@VM-16-9-centos lesson3]$ cd ~
[Jolly.Roger@VM-16-9-centos ~]$ pwd
/home/Jolly.Roger                                    //普通用户的工作目录 /home/XXX
```

***3.man*的使用——通过*man*这个男人获取指令的使用方法**

```C++
1   Executable programs or shell commands                              //默认调用的指令
2   System calls (functions provided by the kernel)                    //系统调用函数
3   Library calls (functions within program libraries)                 //库函数
4   Special files (usually found in /dev)
5   File formats and conventions eg /etc/passwd
6   Games
7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7)
8   System administration commands (usually only for root)
9   Kernel routines [Non standard]
```

***4.which*的使用——查看特定指令的系统路径**

- 指令在Linux里面本质上是一些程序，而程序就是文件.exe文件。既然是文件因此指令在Linux里面也会有存储地址
- 其中还可以查看某些指令具体是指什么
- 同时也可以将一些指令改成特定的符号来代替进行，相当于起别名(关机之后这个替代的符号就会失去作用)

```C++
[Jolly.Roger@VM-16-9-centos file1]$ which ls
alias ls='ls --color=auto'                                        //指令背后的真面目
	/usr/bin/ls                                                   //指令文件在Linux里面的具体地址
[Jolly.Roger@VM-16-9-centos file1]$ alias back='cd ..'            //用其他的符号来代替指令
[Jolly.Roger@VM-16-9-centos file1]$ pwd
/home/Jolly.Roger/lesson3/file1
[Jolly.Roger@VM-16-9-centos file1]$ back
[Jolly.Roger@VM-16-9-centos lesson3]$ pwd
/home/Jolly.Roger/lesson3
```

**5.为什么几乎所有的操作系统都会采用多叉树的形式来管理文件呢？**

**答：**当我们采用绝对路径的方式来进行文件定位时，需要的就是要唯一的定位文件的位置，之所以采用多叉树的形式来管理文件，就是因为每一个子节点只有一个父节点，这就使得在进行文件的查找的时候有唯一的地址找到该文件。

**6.*touch*的使用**

- 创建普通的文件
- 在创建普通的文件的同时也会更新创建的时间和修改时间

```C++
[Jolly.Roger@VM-16-9-centos lesson3]$ touch test1.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ ls -al
total 32
drwxrwxr-x 3 Jolly.Roger Jolly.Roger 4096 Aug  8 15:03 .
drwx------ 7 Jolly.Roger Jolly.Roger 4096 Aug  8 15:01 ..
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug  8 13:59 a.out
drwxrwxr-x 2 Jolly.Roger Jolly.Roger 4096 Aug  8 14:03 file1
-rw-rw-r-- 1 Jolly.Roger Jolly.Roger  309 Aug  8 15:06 test1.txt     //第一次创建时间
-rw-rw-r-- 1 Jolly.Roger Jolly.Roger   71 Aug  8 13:59 test.c
[Jolly.Roger@VM-16-9-centos lesson3]$ touch test1.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ ls -al
total 32
drwxrwxr-x 3 Jolly.Roger Jolly.Roger 4096 Aug  8 15:03 .
drwx------ 7 Jolly.Roger Jolly.Roger 4096 Aug  8 15:01 ..
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug  8 13:59 a.out
drwxrwxr-x 2 Jolly.Roger Jolly.Roger 4096 Aug  8 14:03 file1
-rw-rw-r-- 1 Jolly.Roger Jolly.Roger  309 Aug  8 15:07 test1.txt     //第二次创建时间
-rw-rw-r-- 1 Jolly.Roger Jolly.Roger   71 Aug  8 13:59 test.c
```

**7.标准输出入的介绍**

```C++
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux"
hello Linux
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ cat test2.txt
hello Linux
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ cat test2.txt
hello Linux
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">>test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">>test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">>test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ echo "hello Linux">>test2.txt
[Jolly.Roger@VM-16-9-centos lesson3]$ cat test2.txt
hello Linux
hello Linux
hello Linux
hello Linux
hello Linux
[Jolly.Roger@VM-16-9-centos lesson3]$ cat <test2.txt
hello Linux
hello Linux
hello Linux
hello Linux
hello Linux
```

- 这里面的echo的作用是将后面的内容显示到标准输出当中
- 后面加上了>是一种输出重定向，就是将本来输出到显示器当中的内容重新定向写入到目标文件当中
- 如果这个文件本来就存在的时候，则echo后面得到内容就会覆盖，如果这个文件不存在，运行之后就会重新创建一个新的文件
- 后面加上了>>也是一种输出重定向，只不过与>不同的是它不会将文件当中的内容进行覆盖
- 后面加上了<也是一种输入重定向，将文件当中的内容显示在显示屏当中

**8.Linux里面管道的理解---|** 

- 在自然世界里面管道是用来输送物资的，但是在计算机里面管道是一种入口和出口用来输送数据
- **在指令当中添加管道的时候，就会改变数据的传送方法，这当中默认隐式的发生了重定向**

**9.*mv*命令的理解**

- 如果*mv*命令当中第二个参数的类型是一个路径的时候，那么此时*mv*的作用就是将第一个参数移到第二个路径之下
- 如果*mv*命令当中的第二个参数的类型是一个文件名字的时候，此时*mv*命令的作用就是重命名

#### *2.shell命令的理解*

- 不管是*Linux*还是*Windows*系统，都会有一个内核的代码，但是我们普通的用户是不能够直接与内核代码进行沟通，因为那样的学习成本就会比较的大，因此这里面就会有一个外壳程序，在*Linux*里面叫做*shell*外壳，在*Windows*就是我们比较熟悉*GUI*，也就是图形化界面，两者的相似之处都是便于我们用户进行操作。
- *shell*外壳的作用(承上启下管家的地位)
  - 将使用者的命令进行翻译然后输送给内核进行处理
  - 将核心的处理结果进行翻译然后输送给用户
  - 保护内核代码，防止内核代码被污染
  - 创建子进程来执行具有风险的事

- *shell*是外壳程序的统称，*bash*是一个具体的外壳程序

#### *3.Linux权限的理解---<font color=red>Linux下一切皆是文件</font>*

- *Linux*里面有两种用户 管理员*(root)*，普通的用户*(user)*
- 管理员*(root)*在命令行提示符使用**#**，普通的用户*(user)*在命令行提示符使用**﹩** 

- 文件本身具有权限的属性**(r(读) w(写) x(执行))**，但是权限约束的是人

- *Linux*的用户的类别 拥有者*(owner)* 所属组*(group)* 其他人*(other)*

**超级用户到普通用户之间的切换**

要从root用户切换到普通的用户，需要使用su user，要从普通的用户切换到root的用户，就需要su就可以，但是需要root的密码才能够进行转换

```C++
[Jolly.Roger@VM-16-9-centos lesson6]$ su
Password: 
[root@VM-16-9-centos lesson6]# su Jolly.Roger
[Jolly.Roger@VM-16-9-centos lesson6]$
```

**权限的细节分布图**

![alt](D:\PostgaduateStudies\编程资料\C++资料\博客文档\Linux操作系统\权限细节图.png)

**Linux文件的类型**

![alt](D:\PostgaduateStudies\编程资料\C++资料\博客文档\Linux操作系统\Linux文件的类型.png)

**文件访问权限的设置**

- 用户符号 *u*(拥有者) *g*(所属组) *o*(其他人) *a*(所有人)
- +(增加权限) -(删减权限) =(赋予权限)

```C++
[Jolly.Roger@VM-16-9-centos lesson5]$ chmod a-rwx test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:03 a.out
---------- 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ls
a.out  test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ cat test.c
cat: test.c: Permission denied
[Jolly.Roger@VM-16-9-centos lesson5]$ nano test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ gcc test.c
cc1: fatal error: test.c: Permission denied
compilation terminated.
[Jolly.Roger@VM-16-9-centos lesson5]$ chmod a+rwx  test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:03 a.out
-rwxrwxrwx 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ cat test.c
#include<stdio.h>
int main()
{
	printf("hello Linux!\n");
	return 0;
}
[Jolly.Roger@VM-16-9-centos lesson5]$ nano test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ gcc test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:12 a.out
-r--r--r-- 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ chmod u=w test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:12 a.out
--w-r--r-- 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
```

**所属位置的权限占位**

![alt](D:\PostgaduateStudies\编程资料\C++资料\博客文档\Linux操作系统\权限的所属位置.png)

- 从上面的所属位置可以看出，上述的三个组的位置是相对固定的并且还是二态化，即要不就是rwx要不就是“—”，这就表明我们可以用二进制来表示这个状态。因此我们可以用数字来表示这三组的权限状态，例如777就表示**---------**

```C++
[Jolly.Roger@VM-16-9-centos lesson5]$ chmod 777 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:12 a.out
-rwxrwxrwx 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ chmod 000 test.c
[Jolly.Roger@VM-16-9-centos lesson5]$ ll
total 16
-rwxrwxr-x 1 Jolly.Roger Jolly.Roger 8360 Aug 12 10:12 a.out
---------- 1 Jolly.Roger Jolly.Roger   71 Aug 12 10:03 test.c
```

**目录的权限**

1.可读权限：如果目录没有可读的权限，则不能够使用ls来进行展示里面的内容

2.可写权限：如果没有可写的权限，则不能够在目录里面进行写或者删除操作

3.可执行权限：如果没有可执行的权限，则不能够使用cd进入到目录里面(**进入目录需要x权限**)