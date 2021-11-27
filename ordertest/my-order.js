//头部
$('.myjd div').hide(); 				//我的京东
$('.coll>ol').hide();				//企业采购
$('.cutt div').hide();				//客户服务
$('.online div').hide();			//网站导航
$('.user>div').hide();  			//用户
$('.db div').hide();				//地址
$('.nearly-three-month>ol').hide();   //近三个月
$('.all-stait>ol').hide();
$('.account>ol').hide();               //账户
$('.assess>ol').hide();					//评价
$('.fix .fix3').hide();                 //固定栏
$('.fix ol').hide();                    //特色服务
//用户下的轮播
var num=0;
$('.choose .left').click(function(){
	num--;
	if(num==-1)num=3;
	$('.mid>ol').stop().animate({'left':-152*num+'px'},500);
})
$('.choose .right').click(function(){
	num++;
	if(num==4)num=0;
	$('.mid>ol').stop().animate({'left':-152*num+'px'},500);
})
//manu
$('header>ul>li').hover(function(){
	if($(this).children().eq(0).html()!=''){
		$(this).addClass('bgwhite');
		$(this).children().eq(0).show();
	}
},function(){
	if($(this).children().eq(0).html()!=''){
		$(this).removeClass('bgwhite');
		$(this).children().eq(0).hide();
	}
})
$('.db .up dd').click(function(){
		$('.db>.place').html($(this).html());
})
//fix
$('.fix img').hover(function(){
	$(this).attr('src','../images/joygif_hover.gif');
},function(){
	$(this).attr('src','../images/joygif.gif');
})
var ind=0;
$('.fix ul>li').hover(function(){
	ind=$(this).index();
	if(ind==0){
		$('.fix1 ol').show();
	}else if(ind==1){
		$('.fix_2').css('background','url("../images/ss.png")no-repeat -60px -46px')
	}
},function(){
	if(ind==0){
		$('.fix1 ol').hide();
	}else if(ind==1){
		$('.fix_2').css('background','url("../images/ss.png")no-repeat -8px -53px')
	}
})
$(window).scroll(function(){
	if($(window).scrollTop()>$(window).height()){
		console.log($(window).height());
		$('.fix .fix3').show();
	}else{
		$('.fix .fix3').hide();
	}
})
$('.fix .fix3').click(function(){
	$('html,body').stop().animate({'scrollTop':0},1000);
});
$('.fix1 ol>li').hover(function(){
	$(this).css('margin-left','10px');
},function(){
	$(this).css('margin-left','0px');
})

//nearly-three-month && all-stait
var index=0;
$('.order-table>ul>li').hover(function(){
	index=$(this).index();
	console.log(index);
	if(index==0||index==4){
		$(this).children('ol').show();
	}
},function(){
	if(index==0||index==4){
		$(this).children('ol').hide();
	}
})


$('.nearly-three-month>ol>li').click(function(){
	$('.nearly-three-month span').html($(this).text());
	$('.nearly-three-month>ol>li:nth-of-type(1)').html($(this).text());
	$('.nearly-three-month>ol').hide();
})
$('.all-stait>ol>li').click(function(){
	$('.all-stait span').html($(this).text());
	$('.all-stait>ol>li:nth-of-type(1)').html($(this).text());
	$('.all-stait>ol').hide();
})

//账户/评价
var d=0;
$('.con-left>ul>li').hover(function(){
	d=$(this).index();
	if(d==1||d==2){
		$(this).addClass('acct');
		$(this).children('ol').show();
		$(this).children('span').css('background','url("../images/icon.png") no-repeat 0px -135px')	
	}
},function(){
	if(d==1||d==2){
		$(this).removeClass('acct');
		$(this).children('ol').hide();
		$(this).children('span').css('background','url("../images/icon.png") no-repeat 0px -120px')	
	}
})
//aside new
var arr=['我的常购商品','收藏的内容','京东钢镚'];
for(var i=0;i<$('aside a').length;i++){
	var new1=$('aside a').eq(i).text();
	if(arr.indexOf(new1)!=-1){
	var new2=$('<span></span>');
	$(new2).addClass('span');
	$('aside a').eq(i).append(new2);
	}
}

//猜你喜欢
$('.youlike ul').eq(1).hide();
$('.youlike ul').eq(2).hide();
$('.youlike>p>span').mouseenter(function(){
	var t=$(this).html();
	t=t-1;
	$(this).siblings('span').removeClass('change');
	$(this).addClass('change');
	$('.youlike ul').eq(t).siblings('ul').hide();
	$('.youlike ul').eq(t).show();
})
//order-table
$('.order-top>div').hide();
$('.order-top>div').eq(0).show();

$('.order-top>ul>li').click(function(){
	if($(this).children().length==0){
		$(this).siblings().removeClass('red');
		$(this).addClass('red');
		var index=$(this).index();
		index=index+3;
		$('.order-top>div').eq(index).siblings('div').hide();
		$('.order-top>div').eq(index).show();
	}
})

$('.all a').click(function(){
	$(this).siblings().removeClass('red');
	$(this).addClass('red');	
	var index=$(this).index();
	$('.order-top>div').eq(index).siblings('div').hide();
	$('.order-top>div').eq(index).show();
})


