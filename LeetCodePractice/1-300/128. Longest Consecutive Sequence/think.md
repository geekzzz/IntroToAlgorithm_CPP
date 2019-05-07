注意与lc 53题的区别。
很巧妙的方法，for扫描一遍，每次更新minPrice和maxProfit，maxProfit用max（maxProfit,prices[i] - minPrice）来获取。