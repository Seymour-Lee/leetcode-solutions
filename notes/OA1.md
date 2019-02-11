

一道六角形桌子的问题，大概就是有三个人互相对着坐，剩下的随便坐，然后问你谁在谁旁边那种
面经里有类似的圆桌问题，大概画画图就出来了

六个人团团坐问题，说是三个人不能互相坐对面，那这三个人可以是隔一个人坐或是三连坐，我忘了还有三连坐这种可能，然后第二题就选错了，反应过来的时候已经改不了了，大家要吸取教训，其他题目都是稳稳的我觉得。


阅读都是变种，比如四个人在房间四个角，就出了好几道，主题干都是一样，只要画图就可以秒。

reasoning 部分

1. 2, 5, 26, ___  (前一个数平方加1， 5=2^2+1, 26=5^2+1, ...)
2. tennis -> ...  (面经原题）
3. solar company （面经原题，连着2个问题）
4. ABCD 四个人做8个东西，每人做俩，怎么分配（面经原题，连着3个问题）
5. 买东西要不要付运费，jacob， emma （面经原题）

逻辑题（背熟应用题题干，很重要！！）：

应用题1：A manufacture company has 8 products and 4 divisions. Four divisions are lead by Alan, Betty, Cathy, Diana. The 8 products are: mixer, iron, water pump, geyser, juicer, blender, grinder, and heater. Each division produces 2 products, no 2 divisions produces the same product. Diana’s division produced Geyser, Cathy’s division produces water pump. Mixer and iron areproduced by division lead by Alan and Betty respectively. The division that produces mixer doesn’t produce blender.



应用题二：

Conditions for appointing a distributor, for petroleum gas throughout Georgia, are as follows. The applicant should:

Be an American by nationality

Be in the age group of 21-50 years as on 5th September, 2008

Be at least a high school graduate or any other recognized equivalent

Be a resident of Georgia. He/she should have stayed in Georgia for not less than 5 years, immediately preceding the date of application.

Have a family income of not more than $30,000 annually.

Not have dealership of any oil company

Not have any close relative as a dealer/distributor of any oil company

However,

Restrictions related to annual income would not be applicable to applicants working in corporations, owned or controlled by state departments. Such a case should be referred to the Managing Director

For unemployed applicants who hold at least a bachelor’s degree, conditions (6) and (7) may be waived

If an applicant is from a rural district but is not a resident of Georgia,

 the case may be referred to the Chairman.














## Debug

### 1. boolean checkPalindrome(int num)

判断一个int是不是回文的

return (result == num) --> return (result == temp)



### 2. int countElement(int arr[], int n)

返回arr中， 大于两杯n的数字的个数

for循环少i++， if也不对，改为：

```C++
for(int i = 0; i < n; i++){
    if(arr[i] > doubleN) count++;
}
```



### 3. int distinctElementsCount(int size, int[] element)

返回arr中所有唯一出现的元素

if(flag == 1) --> if(flag == 0)



### 4. appearsKTimes(int size, int inputArray[], int k)

返回arr中， 最大的，出现k次的数字，没有回-1



while后面，加一句if(count == k) res = element;

// switch if 和 else，先判断if(element != inputArray[i])???



### 5. string eliminateVowel(string str)

把str中所有的vowel都删掉

删掉default case中的i++





### 6. int checkArmstrong(int num)

pow.(result, digitCount) --> pow(remainder, digitCount)



### 7. medianValue(int size, int[] arr1, int[] arr2)

else arr[i] = arr2[i] → else arr[i] = arr2[i - size];



### 8. int countDays(int month, int year)

(year % 4 == 0) && (year %100 != 0) || (year % 400 == 0)

```
 if ((y % 4 == 0 and y % 100 != 0) or (y % 400 == 0 and y % 3200 != 0)):
2     print("閏年")
3  else:
4     print("平年")
```

### 9. int countElementRange(int size, int[] inputArray, int low, int high)

(inputArray[i] >= low && inputArray[i] <= high)



### 10. int countA(String str)

if (c == ‘A’ || c == ‘a’)



### 11. int matrixSum(int\[\]\[\] matrix)

while(j < n) sum += matrix[i][j++]; put i++ out of the while(j < n) loop



### 12. int vowelsString(String inputstr)

vcount > (len / 2),还有一个地方要改,但不记得了。。。

把i++移出去

### 13. int getDigitSumParity(int[] arr)

(1)主函数 if (result % 2 ==0)
(2)主函数 if (result == 0) return 1
(3)sum digit函数把 int temp = num %10 和 num = num/10 换一下顺序

主函数里判断奇偶错了，应该把result % 2 ！= 0 改成result % 2 == 0，

此外主函数里对result == 0有一个单独的if statement： if (result == 0) return 0;改成if (result == 0) return 1; 

sum digit 函数也有个经典错误，在loop里把num = num / 10; int temp = num % 10; 改成int temp = num % 10; num = num / 10;  （计算temp应在num变化前）。

### 14. int sumDistinct(int size, int[] inputArray)

sort写在第一行



### 15. int countProduct(int size, int valueofK, int[]priceList)

for (j = 0; j < size; j++)



### 16. ListNode mergeTwoList(ListNode l1, ListNode l2)



### 17. int[] sortArray(int arr[])

if (arr[i] < arr[j]) 冒泡

if (max < arr[j]) 选择

### 18. void printPattern(int n)

add “{ }” for outside for loop



### 19. int countOccurrence(int arr[], int value)







### 20. int countDigits(int num)

加一个temp



### 21. int[] repalceValues(int arr[])

i < len

j < len



### 22. reverseArray(int arr[])

len = len-1



### 23. int[] removeElement(int arr[], int index)

arr[i] = arr[i+1]









distinctNum: 把==改成!=



reverseNum: reverseNum = reverseNum * 10 +i remainder























