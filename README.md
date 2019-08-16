2019-summer-project总体报告

[![Build Status](https://www.travis-ci.org/VamosC/2019-summer-project.svg?branch=master)](https://www.travis-ci.org/VamosC/2019-summer-project)

## 问题及背景

图像处理软件是人们日常生活中经常使用的软件之一，然而现有的软件多数存在功能复杂、冗余庞大导致的启动速度慢等问题。本项目旨在基于我们所学到的图像处理等方面的知识，并结合MVVM框架进行小组合作，实现一款轻量级的图像处理软件(具体要求见[需求分析](./doc/需求分析.md))。



## 开发环境及工具

- 本项目基于**QT5.12.1** 遵循**C++17**标准

- 整体架构基于**MVVM(Model-View-ViewModel)**实现

- 采用**Git**进行版本控制 使用**Travis CI**持续集成

  

## 小组成员

- 梁超（组长）
- 刘韧（组员）
- 周名弦（组员）



## 开发计划及分工

- 第0轮迭代

  - 全体成员讨论需求分析 确定主题
  - 梁超负责持续集成的搭建以及MVVM框架的搭建

- 第1轮迭代

  - 实现保存、撤销、调整亮度对比度、各种滤波等功能
  - 梁超负责Model和ViewModel层
  - 刘韧负责APP层
  - 周名弦负责View层

- 第2轮迭代

  - 实现图像分割、边缘检测、二值化、直方图均值化、加噪声、放大缩放等功能
  - 周名弦负责Model和ViewModel层
  - 梁超负责APP层
  - 刘韧负责View层

- 第3轮迭代

  - 实现人脸检测、人脸标记等高级功能
  - 刘韧负责Model和ViewModel层
  - 周名弦负责APP层
  - 梁超负责View层

  三轮迭代完成后，全体成员将MVVM框架的各个分工都做了一遍。



## 每轮迭代效果说明

### 第0轮迭代

第0轮迭代仅仅实现了一个图像打开功能，如图所示能够在软件的正中央显示打开的图像。

![7](/Users/liangchao/Documents/2019-summer-project/image/7.png)



### 第1轮迭代

通过第0轮搭建的框架，在大家熟悉了框架后开始正式地合作开发。

第1轮迭代实现了调节亮度对比度的功能、各种滤波的功能以及保存图像和撤销的功能。

本轮迭代新增了亮度与对比度调节的界面如下图所示，此外菜单栏上多了相应功能的选项。

#### 调节亮度对比度

![8](/Users/liangchao/Documents/2019-summer-project/image/8.png)

![9](/Users/liangchao/Documents/2019-summer-project/image/9.png)

#### 各种滤波

![10](/Users/liangchao/Documents/2019-summer-project/image/10.png)

#### 保存图像

![11](/Users/liangchao/Documents/2019-summer-project/image/11.png)

#### 均值滤波

![12](/Users/liangchao/Documents/2019-summer-project/image/12.png)

#### 中值滤波

![13](/Users/liangchao/Documents/2019-summer-project/image/13.png)

#### 高斯滤波

![14](/Users/liangchao/Documents/2019-summer-project/image/14.png)

#### 双边滤波

![15](/Users/liangchao/Documents/2019-summer-project/image/15.png)



### 第2轮迭代

第2轮迭代在第一轮迭代的基础上继续增加功能，加入了转化为灰度图、二值化、边缘检测、图像分割、加入噪声、直方图均衡化以及缩放等功能。

本轮的迭代在界面上仅仅是工具栏上增添了新的功能选项。



### 第3轮迭代





### 项目目录树

![1](/Users/liangchao/Documents/2019-summer-project/image/1.png)

![2](/Users/liangchao/Documents/2019-summer-project/image/2.png)

![3](/Users/liangchao/Documents/2019-summer-project/image/3.png)

![4](/Users/liangchao/Documents/2019-summer-project/image/4.png)

![5](/Users/liangchao/Documents/2019-summer-project/image/5.png)

![6](/Users/liangchao/Documents/2019-summer-project/image/6.png)



## 最终运行效果图

