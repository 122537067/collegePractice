package com.demo;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class HelloServlet extends HttpServlet {
	
	public HelloServlet(){
		System.out.println("========HelloServlet");
	}
	
	

	@Override
	protected void service(HttpServletRequest arg0, HttpServletResponse arg1) throws ServletException, IOException {
		System.out.println("========service");
		super.service(arg0, arg1);
	}



	@Override
	public void init() throws ServletException {
		System.out.println("========init");
	}



	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		System.out.println("==========doGet");
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		System.out.println("===========doPost");
	}



	@Override
	public void destroy() {
		
		System.out.println("===========destroy");

		super.destroy();
	}
	
	
	

}
