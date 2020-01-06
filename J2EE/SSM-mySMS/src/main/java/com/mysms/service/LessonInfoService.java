package com.mysms.service;

import com.mysms.dao.ILessonInfoDao;
import com.mysms.iservice.ILessonInfoService;
import com.mysms.model.LessonInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LessonInfoService implements ILessonInfoService{
    
    @Autowired
    private ILessonInfoDao dao;
    
    @Override
    public List<LessonInfo> getAllLessonInfos() throws Exception {
        return this.dao.selectAllLessonInfo();
    }

    @Override
    public void insertLesson(LessonInfo lesson) throws Exception {
        int i = this.dao.insertLessonInfo(lesson);
        if(i==0) throw new Exception("增加失败");
    }

    @Override
    public void deleteLesson(int id) throws Exception {
        int i = this.dao.deleteLessonInfo(id);
        if(i==0) throw new Exception("删除失败");
    }

    @Override
    public void updateLesson(LessonInfo lesson) throws Exception {
        int i = this.dao.updateLessonInfo(lesson);
        if(i==0) throw new Exception("修改失败");
    }

    @Override
    public LessonInfo getLessonById(int id) throws Exception {
        return this.dao.selectLessonInfoById(id);
    }

    @Override
    public LessonInfo getLessonByName(String name) throws Exception {
        return this.dao.selectLessonInfoByName(name);
    }
}
