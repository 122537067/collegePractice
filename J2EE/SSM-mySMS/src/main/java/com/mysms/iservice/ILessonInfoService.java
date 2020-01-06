package com.mysms.iservice;

import com.mysms.model.LessonInfo;

import java.util.List;

public interface ILessonInfoService {

    public List<LessonInfo> getAllLessonInfos() throws Exception;

    public void insertLesson(LessonInfo lesson) throws  Exception;

    public void deleteLesson(int id) throws Exception;

    public void updateLesson(LessonInfo lesson) throws Exception;

    public LessonInfo getLessonById(int id) throws Exception;

    public LessonInfo getLessonByName(String name) throws Exception;

}
