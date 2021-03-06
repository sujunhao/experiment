﻿##R数据分析1


##数据
x <- c(1.2, 4.5, 6.5, 9.3， 1.2, 4.5, 6.5, 9.3)
a <- gl(3, 1, 8)
b <- gl(2, 2, 8)

##gl产生因子
##[1] 1 2 3 1 2 3 1 2
##Levels: 1 2 3

rat <- dat.frame(level = x, group = a)


##方差齐性检验
bartlett.test(x~a, data=rat)


##完全随机区组设计单因素方差分析
aov(x~a, data= rat)

##双因素方差分析
aov(x~a+b, data = rat)

##析因设计方差分析
aov(x~a*b, data= rat)


##两两比较
##t.test
pairwise.t.test(x, a, data=rat, p.adjust.method='holm')
#p.adjust.methods
#c("holm", "hochberg", "hommel", "bonferroni", "BH", "BY",
# "fdr", "none")
