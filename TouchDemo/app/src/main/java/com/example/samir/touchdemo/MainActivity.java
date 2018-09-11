package com.example.samir.touchdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView show = null;
    private TextView type = null;
    private LinearLayout linearLayout = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView() {
        show = (TextView)super.findViewById(R.id.show);
        type = (TextView)super.findViewById(R.id.type);
        linearLayout = (LinearLayout)super.findViewById(R.id.LinearLayout1);
        linearLayout.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                System.out.println("---action get type:"+motionEvent.getToolType(0)+"-----");
                type.setText("触摸类型："+motionEvent.getToolType(0)+";");
                switch (motionEvent.getAction()){
                    case MotionEvent.ACTION_DOWN:
                        System.out.println("---action down-----");
                        show.setText("起始位置为："+"("+motionEvent.getX()+" , "+motionEvent.getY()+")");
                        break;
                    case MotionEvent.ACTION_MOVE:
                        System.out.println("---action move-----");
                        show.setText("移动中坐标为："+"("+motionEvent.getX()+" , "+motionEvent.getY()+")");
                        break;
                    case MotionEvent.ACTION_UP:
                        System.out.println("---action up-----");
                        show.setText("最后位置为："+"("+motionEvent.getX()+" , "+motionEvent.getY()+")");
                        break;
                }
                return true;
            }
        });
    }
}
