package com.sms.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Map;

public class DbHelper {

    private String driverName;
    private String url;
    private String user;
    private String password;

    private Connection con = null;

    public DbHelper(String driverName,String url,String user,String password){
        this.driverName = driverName;
        this.url = url;
        this.user = user;
        this.password = password;
    }


    public void createConnection() throws Exception{
        Class.forName(this.driverName);
        this.con = DriverManager.getConnection(this.url,this.user,this.password);
    }


    public void closeConnection() throws Exception {
        if(con==null) return;
        if(con.isClosed()) return;
        this.con.close();
    }

    public void execute(String sql,Map<String,Object> param) throws Exception {
        if(this.con==null || this.con.isClosed()){
            throw new Exception("璇烽鍏堣皟鐢╟reateConnection鏂规硶鍒涘缓杩炴帴");
        }

        PreparedStatement psmt = this.con.prepareStatement(sql);

        if(param != null){
            int index = 1;
            for(String key:param.keySet()){
                Object value = param.get(key);
                System.out.println(index+","+key+"="+value);

                psmt.setObject(index, value);

                index++;
            }
        }

        psmt.executeUpdate();
    }


    public ResultSet query(String sql,Map<String,Object> param) throws Exception {
        if(this.con==null || this.con.isClosed()){
            throw new Exception("璇烽鍏堣皟鐢╟reateConnection鏂规硶鍒涘缓杩炴帴");
        }

        PreparedStatement psmt = this.con.prepareStatement(sql);

        if(param != null){
            int index = 1;
            for(String key:param.keySet()){
                Object value = param.get(key);
                psmt.setObject(index, value);
                index++;
            }
        }

        ResultSet rs = psmt.executeQuery();

        return rs;
    }


}
