
// 表单数据转换成json字符串
function form2Json(id) {

    var arr = $("#" + id).serializeArray();
    var jsonStr = "";

    jsonStr += '{"Action":"Query",';
    for (var i = 0; i < arr.length; i++) {
        jsonStr += '"' + arr[i].name + '":"' + arr[i].value + '",';
    }
    jsonStr = jsonStr.substring(0, (jsonStr.length - 1));
    jsonStr += '}';

    var json = JSON.parse(jsonStr);
    return json;
}

// datagrid控件初始化
$.extend($.fn.datagrid.methods, {
    init: function (jq, param) {        
        $(jq).datagrid({
            url: (param === undefined || param.url === undefined) ? location.href : param.url,
            fitColumns: true,
            rownumbers: true,
            pageSize: (param === undefined || param.pageSize === undefined) ? 10 : param.pageSize,
            pageList: (param === undefined || param.pageList === undefined) ? [10,20,30,40,50] : param.pageList,
            pagination: true,
            striped: true,
            singleSelect: true,
            idField: "Id",
            loadMsg: '数据加载中，请稍候...',
            title: (param === undefined || param.title === undefined) ? '' : param.title,
            queryParams: (param === undefined || param.queryParams === undefined) ? {} : param.queryParams
        });
    }
});

// 创建树的右键刷新菜单
function createTreeReloadMenu(treeId)
{
    $('body').append('<div id="mmm" style="width:120px;"><div data-options="iconCls:\'icon-reload\'">刷新</div></div>');

    $('#mmm').menu({
        onClick: function (item) {
            if (item.text == "刷新") {
                $('#' + treeId).tree('reload');
            }
        }
    });
}

// tree控件的初始化
$.extend($.fn.tree.methods, {
    init: function (jq, param) {

        $('body').append('<div id="mmm" style="width:120px;"><div data-options="iconCls:\'icon-reload\'">刷新</div></div>');

        $('#mmm').menu({
            onClick: function (item) {
                if (item.text == "刷新") {
                    $(jq).tree('reload');
                }
            }
        });

        $(jq).tree({
            animate: false,
            url: (param === undefined || param.url === undefined) ? location.href : param.url,
            onContextMenu: function (e, node) {
                e.preventDefault();
                $(this).tree('select', node.target);
                $('#mmm').menu('show', {
                    left: e.pageX,
                    top: e.pageY
                });
            }
        });
    }
});

// bool类型的格式化显示：1=是，0=否
function boolFormat(val, row) {
    if (typeof (val) == "undefined") return;
    if (val.length <= 0) return;

    if (val == "true") {
        return '是';
    } else {
        return '否';
    }
}

// 扩展datagrid，点击单元格开始编辑
$.extend($.fn.datagrid.methods, {
    editCell: function (jq, param) {
        return jq.each(function () {
            var opts = $(this).datagrid('options');
            var fields = $(this).datagrid('getColumnFields', true).concat($(this).datagrid('getColumnFields'));
            for (var i = 0; i < fields.length; i++) {
                var col = $(this).datagrid('getColumnOption', fields[i]);
                col.editor1 = col.editor;
                if (fields[i] != param.field) {
                    col.editor = null;
                }
            }
            $(this).datagrid('beginEdit', param.index);
            var ed = $(this).datagrid('getEditor', param);
            if (ed) {
                if ($(ed.target).hasClass('textbox-f')) {
                    $(ed.target).textbox('textbox').focus();
                } else {
                    $(ed.target).focus();
                }
            }
            for (var i = 0; i < fields.length; i++) {
                var col = $(this).datagrid('getColumnOption', fields[i]);
                col.editor = col.editor1;
            }
        });
    },
    enableCellEditing: function (jq) {
        return jq.each(function () {
            var dg = $(this);
            var opts = dg.datagrid('options');
            opts.oldOnClickCell = opts.onClickCell;
            opts.onClickCell = function (index, field) {
                if (opts.editIndex != undefined) {
                    if (dg.datagrid('validateRow', opts.editIndex)) {
                        dg.datagrid('endEdit', opts.editIndex);
                        opts.editIndex = undefined;
                    } else {
                        return;
                    }
                }
                dg.datagrid('selectRow', index).datagrid('editCell', {
                    index: index,
                    field: field
                });
                opts.editIndex = index;
                opts.oldOnClickCell.call(this, index, field);
            }
        });
    }
});

// 刷新父窗体的数据
function returnReload() {
    var winId = getQueryString('WindowDivId');
    var id = getQueryString('ReloadControl');
    var type = getQueryString('ReloadControlType');
    var fromTabTitle = getQueryString("FromTabTitle");

    if (fromTabTitle) {
        var tabWindow = window.top.getWindowByTabTitle(fromTabTitle);
        if (type == "tree") {
            tabWindow.$("#" + id).tree('reload');
        }
        else {
            tabWindow.$("#" + id).datagrid('reload');
            tabWindow.$("#" + id).datagrid("uncheckAll");
        }
    }
    else {
        if (type == "tree") {
            window.parent.$("#" + id).tree('reload');
        }
        else {
            window.parent.$("#" + id).datagrid('reload');
            window.parent.$("#" + id).datagrid("uncheckAll");
        }
    }
}

// 刷新待办待阅数据
function reloadMsgData()
{
    if (window.top.$("#dgMsg")) {
        window.top.$("#dgMsg").datagrid('reload');
    }
}