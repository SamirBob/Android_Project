package com.example.samir.helloandroid;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //绑定一个Button控件
        Button btn01 = (Button)findViewById(R.id.button1);

        //给按钮添加侦听事件
        btn01.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //弹出一个内容为“Hello Android”的提示
                Toast toast = Toast.makeText(getApplicationContext(),"HelloAndroid!",Toast.LENGTH_SHORT);
                toast.show();
            }
        });
    }
}
