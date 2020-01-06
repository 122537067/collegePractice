package com.zhengjiaxin.test;

import java.lang.reflect.Method;

import org.springframework.aop.ThrowsAdvice;

public class ErrorLogger implements ThrowsAdvice{
	public void afterThrowing(Method method,Object[] args,Object target,Exception ex){
		System.out.println("调用"+target+"的方法"+method.getName()+"发生了异常："+ex.getMessage());
	}
}
