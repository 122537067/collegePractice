package com.mysms.service;

import com.mysms.dao.IScoreInfoDao;
import com.mysms.iservice.IScoreInfoService;
import com.mysms.model.ScoreInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ScoreInfoService implements IScoreInfoService{

    @Autowired
    public IScoreInfoDao dao;

    @Override
    public List<ScoreInfo> getAllScoreInfos() throws Exception {
        return this.dao.selectAllScoreInfo();
    }

    @Override
    public void insertScore(ScoreInfo lesson) throws Exception {
        int i = this.dao.insertScoreInfo(lesson);
        if(i==0) throw new Exception("增加失败");
    }

    @Override
    public void deleteScore(int id) throws Exception {
        int i = this.dao.deleteScoreInfo(id);
        if(i==0) throw new Exception("删除失败");
    }

    @Override
    public void updateScore(ScoreInfo lesson) throws Exception {
        int i = this.dao.updateScoreInfo(lesson);
        if(i==0) throw new Exception("修改失败");
    }

    @Override
    public ScoreInfo getScoreById(int id) throws Exception {
        return this.dao.selectScoreInfoById(id);
    }
}
