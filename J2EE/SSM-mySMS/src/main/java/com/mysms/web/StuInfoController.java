package com.mysms.web;

import com.mysms.iservice.IStuInfoService;
import com.mysms.model.StuInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@Controller
@RequestMapping("/stuinfo")
public class StuInfoController extends BaseController{

    @Autowired
    private IStuInfoService service;

    @RequestMapping(value="/list",method= RequestMethod.GET)
    public String getlist(HttpServletRequest request, HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"StuSearch");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "stuinfo/list";
    }

    @RequestMapping(value="/list",method=RequestMethod.POST)
    @ResponseBody
    public List<StuInfo> list() throws Exception{
        return this.service.getAllStuInfos();
    }

    @RequestMapping(value = "/add",method = RequestMethod.GET)
    public String getadd(HttpServletRequest request,HttpServletResponse response) throws IOException {
        try {
            this.validPermission(request,"StuAdd");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        return "stuinfo/add";
    }

    @RequestMapping(value = "/add",method = RequestMethod.POST)
    @ResponseBody
    public String add(HttpServletRequest request){
        StuInfo stu = new StuInfo();
        stu.setNo(request.getParameter("No"));
        stu.setName(request.getParameter("Name"));
        stu.setKlass(request.getParameter("Klass"));
        try {
            this.service.insertStu(stu);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/delete",method = RequestMethod.POST)
    @ResponseBody
    public String delete(HttpServletRequest request){
        try {
            this.validPermission(request,"StuDel");
            String id = request.getParameter("id");
            this.service.deleteStu(Integer.parseInt(id));
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getedit",method = RequestMethod.GET)
    public String getEdit(HttpServletRequest request,HttpServletResponse response, Model model) throws Exception {
        try {
            this.validPermission(request,"StuModify");
        } catch (Exception e) {
            return this.exp(response,e);
        }
        StuInfo stu = this.service.getStuById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectStu",stu);
        return "/stuinfo/edit";
    }

    @RequestMapping(value = "/edit",method = RequestMethod.POST)
    @ResponseBody
    public String Edit(HttpServletRequest request){
        StuInfo stu = new StuInfo();
        stu.setId(Integer.parseInt(request.getParameter("Id")));
        stu.setNo(request.getParameter("No"));
        stu.setName(request.getParameter("Name"));
        stu.setKlass(request.getParameter("Klass"));
        try {
            this.service.updateStu(stu);
            return "success";
        } catch (Exception e) {
            return e.getMessage();
        }
    }

    @RequestMapping(value = "/getdetail",method = RequestMethod.GET)
    public String getDetail(HttpServletRequest request,Model model) throws Exception {
        StuInfo stu = this.service.getStuById(Integer.parseInt(request.getParameter("id")));
        model.addAttribute("selectStu",stu);
        return "/stuinfo/detail";
    }

}
