<br /><br /><br />
<p align="center">
  <img width="700" src="assets/arithmetics.jpg" />
</p>
<br /><br />

# pointer-arithmetics-challenge
> Retrieving a pointer to a structure given a pointer to one of its member.

Current version: **1.0.0**

## 📋 Table of content

- [Introduction](#-introduction)
- [See also](#-see-also)

## 🚀 Introduction

> While I was taking a programming contest and came across an interesting challenge related to pointer arithmetic in C. I decided to create a write-up on the subject to expose the problem and the proposed solution.

The goal of the challenge was to retrieve the pointer to a structure given a pointer to one of its member. We're also given the type of the structure as well as the name of the members and their type within the structure. Furthermore, this should be done independently of the number of members in the structure or its size.

For the purpose of the challenge, we will consider the following structure of type `t_struct` which holds a float, an int (our member, aptly named member) and a char :

```c
typedef struct {
  float f;
  int member;
  char c;
} t_struct;
```

We need to provide a function that takes a pointer to a member of a structure and returns a pointer to the actual structure. The function must be prototyped as follow :

```c
t_struct* get_struct_ptr(void* member);
```

In order to achieve this we will need to :

- Find out what the offset between the top of the structure and the actual address of the given member is.
- Provide a solution that must be compiler and platform agnostic as well as not being sensitive to the layout of the structure.

## 👀 See also

- The [`offsetof()`](http://en.wikipedia.org/wiki/Offsetof) macro.
