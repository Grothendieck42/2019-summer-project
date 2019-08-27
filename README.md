# 2019-summer-project总体报告

[![Build Status](https://www.travis-ci.org/VamosC/2019-summer-project.svg?branch=master)](https://www.travis-ci.org/VamosC/2019-summer-project)

## 目录
- [2019-summer-project总体报告](#2019-summer-project总体报告)
    - [问题及背景](#问题及背景)
    - [开发环境及工具](#开发环境及工具)
    - [小组成员](#小组成员)
    - [开发计划及分工](#开发计划及分工)
    - [每轮迭代效果说明](#每轮迭代效果说明)
        - [第0轮迭代](#第0轮迭代)
        - [第1轮迭代](#第1轮迭代)
        - [第2轮迭代](#第2轮迭代)
        - [第3轮迭代](#第3轮迭代)
        - [项目目录树](#项目目录树)
    - [最终运行效果图](#最终运行效果图)

## 问题及背景

图像处理软件是人们日常生活中经常使用的软件之一，然而现有的软件多数存在功能复杂、冗余庞大导致的启动速度慢等问题。本项目旨在基于我们所学到的图像处理等方面的知识，并结合MVVM框架进行小组合作，实现一款轻量级的图像处理软件(具体要求见[需求分析](./doc/需求分析.md))。



## 开发环境及工具

- 本项目基于**QT5.12.1** 遵循**C++17**标准

- 整体架构基于**MVVM**（Model-View-ViewModel）实现

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

![7](./image/7.png)



### 第1轮迭代

通过第0轮搭建的框架，在大家熟悉了框架后开始正式地合作开发。

第1轮迭代实现了调节亮度对比度的功能、各种滤波的功能以及保存图像和撤销的功能。

本轮迭代新增了亮度与对比度调节的界面如下图所示，此外菜单栏上多了相应功能的选项。

#### 调节亮度对比度

![8](./image/8.png)

![9](./image/9.png)

#### 各种滤波

![10](./image/10.png)

#### 保存图像

![11](./image/11.png)

#### 均值滤波

![12](./image/12.png)

#### 中值滤波

![13](./image/13.png)

#### 高斯滤波

![14](./image/14.png)

#### 双边滤波

![15](./image/15.png)



### 第2轮迭代

第2轮迭代在第一轮迭代的基础上继续增加功能，加入了转化为灰度图、二值化、边缘检测、图像分割、加入噪声、直方图均衡化以及缩放等功能。

本轮的迭代在界面上仅仅是工具栏上增添了新的功能选项，如下图所示。

![16](./image/16.png)

![17](./image/17.png)

![18](./image/18.png)

#### 转化为灰度图

![19](./image/19.png)

#### 二值化

![20](./image/20.png)

#### 边缘检测

![21](./image/21.png)

#### 图像分割

![22](./image/22.png)

#### 彩色直方图均衡化

![23](./image/23.png)

#### 灰度直方图均衡化

![24](./image/24.png)

#### 图像去雾 

![25](./image/25.png)

![26](./image/26.png)

#### 对数变换

![27](./image/27.png)

![28](./image/28.png)

#### 拉普拉斯锐化

![29](./image/29.png)

![30](./image/30.png)

#### 高斯噪声

![31](./image/31.png)

#### 椒盐噪声

![32](./image/32.png)

#### 导向滤波

![33](./image/33.png)

#### 伽马变换

![34](./image/34.png)

![35](./image/35.png)

#### 图像放大

![36](./image/36.png)

#### 图像缩小

![37](./image/37.png)



### 第3轮迭代

第3轮迭代在第2轮的基础上增加一些高级功能比如说人脸识别、人脸标记、人脸美化、生成大头照等。

本轮在界面上没有做过多的修改，主要是训练了模型并加入到我们的软件中。

#### 人脸识别

![38](./image/38.png)

### 项目目录树

![1](./image/1.png)

![2](./image/2.png)

![3](./image/3.png)

![4](./image/4.png)

![5](./image/5.png)

![6](./image/6.png)



## 最终运行效果图

![39](./image/39.png)