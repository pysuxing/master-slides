# 面向并行处理器的稠密线性代数数学库关键技术研究

## 研究背景

- 稠密线性代数数学库的重要性
  + 高性能计算领域经典benchmark LINPACK
  + 数值天气预报、石油勘探、地震数据处理等科学工程计算应用
- 计算机体系结构的发展现状
  + 多层次的并行计算能力
    * 核内指令级并行SIMD
    * 多核处理器的主流地位
    * 众核（协）处理器的发展趋势
  + 复杂化的存储层次结构
    * 多层级的cache存储结构
    * 多样化的cache互联结构
- 面向并行处理器的稠密线性代数数学库的研究发展现状
  + 发展现状
    * BLAS与LAPACK程序库的提出及标准化
    * 基于高性能矩阵乘法可以实现完整的高性能BLAS程序库
    * 以寄存器级实现的外乘操作作为矩阵乘法的基本构造单元可以取得峰值浮点性能
    * 分块求解可以有效地利用片上高速cache从而隐藏访问主存的时延
  + 取得峰值性能的必要条件
    * 有效利用并行SIMD指令达到峰值浮点性能
    * 有效利用cache高速缓存，重叠计算与访存
    * 合理划分、调度计算任务在多核及重核处理器上取得良好可扩展性
  + 现存挑战
    * 取得峰值性能的最优化实现严重平台相关。单以矩阵乘法程序为例，当前的实现
      可以通过参数配置实现分部分代码的平台可移植性，但核心的计算程序仍需要专家
      手动编写汇编代码，并且，在进行性能调优时，核心计算代码与分块调度代码是紧耦合的，
      程序的整体性能是两部分代码共同作用的结果，不利于分析各部分代码对整体性能的影响
    * 随着处理器核数的进一步增多与存储层次的进一步复杂化，
      现有的实现策略已经不能很好地适应新的处理器体系结构
    * 基于高性能矩阵乘法能够实现完整的BLAS程序库，但调用BLAS程序接口编写更高层次
      的程序时，为了实现最优性能仍然需要大量的调优工作，如LINPACK
    * 现有的BLAS与LAPACK接口标准还存在一些限制，如不支持跨类型运算与非连续存储格式等
## 研究内容
FIXME: 是否有更为合适的提法

- 针对稠密线性代数运算的编译优化技术研究
  + 问题描述：
    * 稠密线性代数程序中存在若干个的核心计算函数（kernel）
    * kernel函数是程序整体性能的决定性因素之一
    * kernel函数的最优实现是严重平台相关的
  + 研究现状：
    * 专家编写汇编代码（GotoBLAS，OpenBLAS，BLIS）
    * 自动生成并选取kernel（ATLAS）
    * POET
    * BLIS组的cgo16
  + 研究思路：
    * 总结专家知识，提取稠密线性代数程序中的核心指令，
      定位处理器微体系结构中影响程序性能的关键参数
    * 利用开源编译器框架，应用专家优化策略，取得最优性能的同时获得平台可移植性
  + 预期创新点：
    * 针对稠密线性代数问题的编译优化技术
    * 可移植的最优性能
- 面向多核及众核处理器的分块调度策略研究
  + 问题描述：
    * 现有的分块调度策略一般基于inclusive cache的存储模型，这不符合一些处理器的实际情况，
      如FT-1500A处理器配备了小容量exclusive的L3 cache
    * 众核处理器的出现使存储层次结构更加多样化、复杂化，如下一代Xeon PHI众核处理器KNL配备了
      mesh互联的二级cache网络，这在选调度策略时需要纳入考虑
    * 超线程的引入，对分块策略提出了新的要求
  + 研究现状：
    * 采用自动调优的方法选择分块大小（ATLAS）
    * 采用分析方法选择分块大小（BLIS）
    * 采用二维并行代替一维并行改进在众核处理器上的可扩展性（BLIS）
  + 研究思路：
    * 程序运行过程中，数据在存储层次结构中的流动行为是十分复杂的，
      但可以通过分层的思想逐层分析
    * 分块与调度的策略也根据存储器本身性质逐层选取，以模块化的方式组合得到整体的最优策略
  + 预期创新点：
    * 层次化的性能分析模型，可以适用于更加复杂的存储层次结构
    * 层次化模型下的自动调优工具
- 适用于一般稠密线性代数问题的通用优化技术研究
  + 问题描述：
    * 调用高性能BLAS库实现更高层次的线性代数程序时，
      仍需采用分块等优化手段才能达到最优整体性能，
      这其中的优化参数同样是严重平台相关的
    * BLAS库的接口限制，使得某些情况下必须通过数据拷贝、转存来适应接口，造成性能损失
  + 研究现状：
    * 通过参数调优等手动优化措施达到最优性能
    * 提供更加通用的类BLAS库（BLIS，初步探索）
  + 研究思路
    * 通过分析BLAS、LAPACK等接口标准，发现常见的稠密线性代数问题的求解过程，
      都可以少量基本矩阵操作组合得到
    * 并且，这些稠密线性代数程序多数可以采用分块递归的形式描述，这种描述方式
      适合映射到处理器的存储层次结构上实现
  + 预期创新点
    * 适用于一般的稠密线性代数问题的代码自动生成与调优技术
    * 支持跨类型与非连续存储运算
- 面向稠密线性代数的领域语言研究
  + 问题描述
    * 现有的高性能程序一般使用FORTRAN与C语言编写，编写难度大，维护成本高，性能可移植性差
  + 研究现状
    * LGen编译器
    * 用于科学计算的脚本语言（Matlab，Octave，Python）
  + 研究思路
    * 设计一种更加高层的领域语言，专门用于描述求解稠密线性代数问题
    * 基于以上面向并行处理器平台的针对稠密线性代数计算提出的优化技术，为这种语言提供
      高效的编译实现，并可以通过C语言调用
  + 预期创新点
    * 面向稠密线性代数的领域语言，表达简洁，性能优化，可移植性强

## 研究基础

- 课题组在优化高性能数学库方面有持续性投入
- 熟悉高性能矩阵乘法实现的关键优化技术，了解现有开源BLAS库的开发现状
- 掌握经典的编译器技术，熟悉开源编译器LLVM的代码框架
- 由新南威尔士大学薛京灵教授长期指导，薛教授是编译领域资深专家
- 课题组可以提供优秀的实验环境与设备

## 预期成果

- 针对稠密线性代数问题的编译优化技术，为核心kernel函数的产生可移植的高性能实现
- 自动产生适用于复杂存储层次结构的分块调度优化策略
- 自动生成、调优一般稠密线性代数问题的高性能实现
- 面向稠密线性代数的领域语言

作为一个完整的博士课题，希望能够提出一套高性能稠密线性代数数学库的完整解决方案

## 时间安排

2016.01-2016.04    稠密线性代数问题的编译优化技术             基于LLVM的编译优化代码
2016.05-2016.07    适用于复杂存储层次的分块调度优化策略       会议论文一篇
2016.08-2016.12    为一般稠密线性代数问题提供自动化实现技术   会议论文一篇
2017.01-2017.05    设计实现面向稠密线性代数的领域语言         期刊论文一篇
2017.06-2017.10    完善已有实验，完善项目代码，撰写博士论文   成熟的工程项目
2017.11-1017.11    修改博士论文，答辩                         博士论文
