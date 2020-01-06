package com.zhengjiaxin.aop;

import java.lang.reflect.Method;

import org.springframework.aop.AfterReturningAdvice;

public class LoggerAfterReturning implements AfterReturningAdvice{
	@Override
	public void afterReturning(Object returnValue, Method method, Object[] arguments, Object target) throws Throwable {
		System.out.println("调用"+target+"的方法"+method.getName()+",返回值是："+returnValue);
	}
}
