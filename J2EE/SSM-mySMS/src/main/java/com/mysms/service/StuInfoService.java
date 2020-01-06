package com.mysms.service;

import com.mysms.dao.IStuInfoDao;
import com.mysms.iservice.IStuInfoService;
import com.mysms.model.StuInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class StuInfoService implements IStuInfoService{


    @Autowired
    private IStuInfoDao dao;

    @Override
    public List<StuInfo> getAllStuInfos() throws Exception {
        return this.dao.selectAllStuInfo();
    }

    @Override
    public void insertStu(StuInfo Stu) throws Exception {
        int i = this.dao.insertStuInfo(Stu);
        if(i==0) throw new Exception("增加失败");
    }

    @Override
    public void deleteStu(int id) throws Exception {
        int i = this.dao.deleteStuInfo(id);
        if(i==0) throw new Exception("删除失败");
    }

    @Override
    public void updateStu(StuInfo Stu) throws Exception {
        int i = this.dao.updateStuInfo(Stu);
        if(i==0) throw new Exception("修改失败");
    }

    @Override
    public StuInfo getStuById(int id) throws Exception {
        return this.dao.selectStuInfoById(id);
    }

    @Override
    public StuInfo getStuByName(String name) throws Exception {
        return this.dao.selectStuInfoByName(name);
    }
}
