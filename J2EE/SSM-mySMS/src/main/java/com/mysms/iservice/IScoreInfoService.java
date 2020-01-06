package com.mysms.iservice;

import com.mysms.model.ScoreInfo;

import java.util.List;

public interface IScoreInfoService {

    public List<ScoreInfo> getAllScoreInfos() throws Exception;

    public void insertScore(ScoreInfo lesson) throws  Exception;

    public void deleteScore(int id) throws Exception;

    public void updateScore(ScoreInfo lesson) throws Exception;

    public ScoreInfo getScoreById(int id) throws Exception;
    
}
