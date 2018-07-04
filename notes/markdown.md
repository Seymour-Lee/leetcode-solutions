## 一、段落与换行

在Markdown里，一个换行不会另起一行，只有两个及以上的换行会另起一行。每一行的行首不能有空格和缩进。



## 二、标题

Markdown用#来标记标题，#后需要跟一个空格。

```markdown
# Heading 1
## Heading 2
### Heading 3
#### Heading 4
##### Heading 5
```



## 三、列表

### 无序列表

```markdown
* Item 1
* Item 2
* Item 3
	* Item 3.1
	* Item 3.2
```

* Item 1 
* Item 2 
* Item 3 
  * Item 3.1 
  * Item 3.2



### 有序列表

```markdown
1. Item 1
2. Item 2
3. Item 3
```

1. Item 1
2. Item 2
3. Item 3



## 四、链接

```markdown
[Google](https://www.google.com)
```

[Google](https://www.google.com)



## 五、图片

```markdown
![Google](https://www.google.com.hk/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png)
```

![Google](https://www.google.com.hk/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png)





## 六、粗体和斜体

```markdown
**粗体**  *斜体*
```

**粗体**  *斜体*



## 七、代码

### 文字中的代码

```markdown
文字中插入`#include <iostream>`一段代码
```

文字中插入`#include <iostream>`一段代码



### 代码块

```markdow
​```C++
int
```

```c++
int
```



## 八、引用

```markdown
> reference
> some
> ## 这是一个标题
> > contain
```

> > reference
> > some
> >
> > ## 这是一个标题
> > > contain



## 九、反斜杠（转义字符）

```markdown
\\
\`
\*
\_
\{\}
\[\]
\(\)
\#
\+
\-
\.
\!
```

\\ \` \* \_ \{\} \[\] \(\) \# \+ \- \. \!



## 十、分割线

```markdown
***
---
___
```

***

---

___



## 十一、Others

### 发送电子邮件

```markdown
[to Yiming](mailto:buptliyiming@outlook.com?subject=主题)
```

[to Yiming](mailto:buptliyiming@outlook.com?subject=主题)



### 页面内跳转

```markdow
[跳转至一、段落与换行](##一、段落与换行)
```

[跳转至一、段落与换行](##一、段落与换行)



### 参考式链接

```markdown
有的[链接][1]会被使用多次，此时可使用[参考式链接][1]。
[1]: https://www.google.com
```

 有的[链接][1]会被使用多次，此时可使用[参考式链接][1]。

[1]: https://www.google.com



### 文字上标和下标

```markdown
H<sub>2</sub>O
X<sup>2</sup>+2x+1
```

H<sub>2</sub>O 

X<sup>2</sup>+2x+1



## 十二、公式

