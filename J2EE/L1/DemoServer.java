package com.demo;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class DemoServer {
	
	public static void main(String[] args) throws Exception{
		ServerSocket serverSocket = new ServerSocket(9000);
		Socket socket = serverSocket.accept();
		
		InputStream in = socket.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		
		OutputStream socketOut = socket.getOutputStream();
		PrintWriter pw = new PrintWriter(socketOut,true);
		
		char[] buf = new char[1024];
		br.read(buf);
		
		String request = new String(buf);
		
		System.out.println(request);
		
		FileInputStream fileIn = null;
		
		String firstLineOfRequest=request.substring(0,request.indexOf("\r\n"));
		
		System.out.println("firstLineOfRequest="+firstLineOfRequest);
		
		if(firstLineOfRequest.indexOf("login.html") != -1){
			fileIn = new FileInputStream("login.html");
			
			byte[] bufFile = new byte[1024];
			fileIn.read(bufFile);
			
			fileIn.close();
			
			String content = new String(bufFile);
			
			System.out.println(content);
			
			pw.println(content);
		}
		else{
			StringBuffer sb=new StringBuffer();
			sb.append("HTTP/1.1 200 OK\r\n");
	        sb.append("Content-Type:text/html\r\n\r\n");
	        sb.append("<html>");
	        sb.append("<head>");
	        sb.append("</head>");
	        sb.append("<body>");
	        sb.append("<h1>404</h1>");
	        sb.append("</body>");
	        sb.append("</html>");
			
			pw.println(sb.toString());
			
			
		}
		
		socket.close();
		
		System.out.println("ok");

	}

}
