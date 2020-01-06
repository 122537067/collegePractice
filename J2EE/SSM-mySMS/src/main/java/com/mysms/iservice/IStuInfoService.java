package com.mysms.iservice;

import com.mysms.model.StuInfo;

import java.util.List;

public interface IStuInfoService {

    public List<StuInfo> getAllStuInfos() throws Exception;

    public void insertStu(StuInfo Stu) throws  Exception;

    public void deleteStu(int id) throws Exception;

    public void updateStu(StuInfo Stu) throws Exception;

    public StuInfo getStuById(int id) throws Exception;

    public StuInfo getStuByName(String name) throws Exception;
    
}
