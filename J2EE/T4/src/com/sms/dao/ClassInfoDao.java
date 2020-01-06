package com.sms.dao;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import com.sms.model.ClassInfo;

public class ClassInfoDao extends BaseDao {



    public ClassInfoDao(HttpServletRequest request){
        super(request);
    }


    public void add(ClassInfo model) throws Exception{
        DbHelper db = this.createDbHelper();

        Map<String,Object> param = new LinkedHashMap<String,Object>();
        param.put("Name",model.getName());
        db.createConnection();

        db.execute("insert into ClassInfo(Name) values(?)", param);

        db.closeConnection();
    }

    public void update(ClassInfo model) throws Exception{
        DbHelper db = this.createDbHelper();

        Map<String,Object> param = new LinkedHashMap<String,Object>();
        param.put("Name",model.getName());
        param.put("Id",model.getId());

        db.createConnection();

        db.execute("update ClassInfo set Name=? where Id=?", param);

        db.closeConnection();
    }

    public ClassInfo get(long id) throws Exception{
        DbHelper db = this.createDbHelper();

        Map<String,Object> param = new LinkedHashMap<String,Object>();
        param.put("Id",id);

        db.createConnection();

        ResultSet rs = db.query("select * from ClassInfo where Id=?", param);

        ClassInfo model = null;

        if(rs.next()){
            model = new ClassInfo();
            model.setId(rs.getLong(1));
            model.setName(rs.getString(2));
        }

        db.closeConnection();

        return model;
    }

    public void delete(long id) throws Exception{
        String sql = "delete from ClassInfo where Id=?";
        Map<String,Object> param = new LinkedHashMap<String,Object>();
        param.put("Id",id);

        DbHelper db = this.createDbHelper();
        db.createConnection();
        db.execute(sql, param);
        db.closeConnection();
    }

    public List<ClassInfo> query(String name) throws Exception{
        String sql = "select * from ClassInfo";
        if(name!=null && name.length()>0){
            sql += " where Name like '%"+name+"%'";
        }

        DbHelper db = this.createDbHelper();

        db.createConnection();

        ResultSet rs = db.query(sql, null);

        List<ClassInfo> list = new ArrayList<ClassInfo>();

        while(rs.next()){
            ClassInfo model = new ClassInfo();
            model.setId(rs.getLong(1));
            model.setName(rs.getString(2));

            list.add(model);
        }

        db.closeConnection();

        return list;
    }

}
