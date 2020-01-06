package com.zhengjiaxin.common;

import java.io.BufferedReader;

import javax.servlet.http.HttpServletRequest;

public class JsonHelper {
	
	public static String readJSONData(HttpServletRequest request) {
        StringBuffer json = new StringBuffer();
        String lineString=null;
        
        try {
            BufferedReader reader = request.getReader();
            while ((lineString=reader.readLine())!=null) {
                json.append(lineString);                
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        
        return json.toString();
    }

}