package com.zhengjiaxin.aop;

import java.lang.reflect.Method;
import java.util.Arrays;

import org.springframework.aop.MethodBeforeAdvice;

public class LoggerBefore implements  MethodBeforeAdvice{
	@Override
	public void before(Method method, Object[] arguments, Object target) throws Throwable {
		System.out.println("调用"+target+"的方法"+method.getName()+",参数是："+Arrays.toString(arguments));
	}
}
