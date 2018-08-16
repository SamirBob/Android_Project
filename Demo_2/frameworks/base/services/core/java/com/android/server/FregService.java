package com.android.server;
 
import android.content.Context;
import android.os.IFregService;
import android.util.Slog;
 
/**
 * @hide
 */
public class FregService extends IFregService.Stub{
    private static final String TAG = "FregService";
 
    private int mPtr = 0;
 
    FregService(){
        mPtr = freg_init_native();
 
        if (0 == mPtr)
        {
            Slog.e(TAG, "Failed to initialize freg service.");
        }
    }
 
    public void setVal(int val){
        if (0 == mPtr){
            Slog.e(TAG, "Freg service is not initialized.");
            return;
        }
        setVal_native(mPtr, val);
    }
 
    public int getVal(){
        if (0 == mPtr){
            Slog.e(TAG, "Freg service is not initialized.");
            return 0;
        }
 
        return getVal_native(mPtr);
    }
 
    private static native int freg_init_native();
    private static native void setVal_native(int ptr, int val);
    private static native int getVal_native(int ptr);
};
