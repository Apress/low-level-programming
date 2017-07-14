union vec3d {
    struct {
        double x; 
        double y;
        double z;
    };
    double raw[3];
};

union vec3d vec;
