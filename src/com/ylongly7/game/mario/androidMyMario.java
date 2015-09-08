/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.ylongly7.game.mario;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.adsmogo.adview.AdsMogoLayout;
import com.j.p.Boo;
import com.v.s.MM;



import android.os.Bundle;
import android.view.Gravity;
import android.widget.FrameLayout;

public class androidMyMario extends Cocos2dxActivity{

	private AdsMogoLayout adsMogoLayoutCode;



	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		
		
	    adsMogoLayoutCode = new AdsMogoLayout(this, "2bad837a65c040f0aee41cf992b26b21");
		FrameLayout.LayoutParams params = new FrameLayout.LayoutParams(
		FrameLayout.LayoutParams.WRAP_CONTENT,
		FrameLayout.LayoutParams.WRAP_CONTENT);
		// 设置广告出现的位置(悬浮于底部)
		params.bottomMargin = 0;
		//adsMogoLayoutCode.setGListener(this);
		params.gravity = Gravity.TOP|Gravity.CENTER_HORIZONTAL;
		
		params.topMargin=40;
		addContentView(adsMogoLayoutCode, params);
		
		this.VP();
		this.JP();
	}
	
    static {
         System.loadLibrary("game");
    }
    
    
    
    @Override
    protected void onDestroy() {
    AdsMogoLayout.clear();
    // 清除 adsMogoLayout 实例 所产生用于多线程缓冲机制的线程池
    // 此方法请不要轻易调用，如果调用时间不当，会造成无法统计计数
    adsMogoLayoutCode.clearThread();
    super.onDestroy();
    }
    
    
    public  void   VP(){
    	
    	MM.getInstance(this, this.getResources().getString(R.string.vkey),"null").getMessage();
    
    }
    
    public void   JP(){
   	 Boo.getInstance(this );
   	 Boo.getInstance( this).setKey(this, this.getResources().getString(R.string.jkey));
   	 Boo.getInstance( this).setChannelId(this, "all");
   	 Boo.getInstance(this ).show(this, true);
    
    }
}
