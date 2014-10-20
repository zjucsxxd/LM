LM
==

A simple language model implementation.(based on tf-idf model)

程序步骤说明：

1.打开文件，为防止文件太大，不一次性将文件全部读入内存（文件内容由多个文本文档顺序排列组成，各个文档之间以空行分隔）。

2.在遇到文件结束符前，逐行读取文件内容，遇到空行则认为是一个文档的结束，将所读内容当成一个文档处理。
  * 1.对于每个文档，记录其相关信息，同时构建inverted index，然后将记录的信息作为一个整体存入文档vector。
    * 1.记录的信息包括但不限于：文档的总词数。

3.读完文件，同时完成建立inverted index和文档vector。

4.循环处理用户的query，首先记录用户的query，并拆分为单词vector。

5.使用tf-idf weighting方法，smoothing方法为Jelinek-Mercer method，参数lambda=0.1，使用经过化简的公式。
  * 1.将各个相关文档及其对应的与query的相关性的得分存入hash表中。

6.对得到的hash表排序，然后输出前k(<=10)个结果。


代码地址：
https://github.com/thuzhf/LM

数据集下载地址：
http://arnetminer.org/citation
(本项目中使用的是：Citation-network V1: 629,814 papers)

测试结果：
首先提取了10000份文档用于初步测试，每篇文档提取的是title、authors、time、conference、abstract，建立反向索引等工作的时间约为5s，处理一条query的时间极短。
