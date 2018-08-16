private void startOtherServices() {
    ......
    if (mFactoryTestMode != FactoryTest.FACTORY_TEST_LOW_LEVEL) {
        ......
        try{
                Slog.i(TAG, "Freg Service");
                ServiceManager.addService("freg", new FregService());
            } catch (Throwable e) {
                Slog.e(TAG, "Failure staring Freg Service", e);
            }
    ....
    }
}
