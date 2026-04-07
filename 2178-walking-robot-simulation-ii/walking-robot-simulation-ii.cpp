class Robot {
public:
    int peri;
    int w=0,h=0;
    int dir=0;
    int xx=0,yy=0;
    Robot(int width, int height) {
        peri=2*(width+height)-4;
        w=width;
        h=height;
    }
    
    void step(int num) {
        if(peri==0) return ;
        num=num%peri;
        if(num==0){
            if(xx==0 && yy==0){
                dir=3;
            }
        }
       
        while(num--){
            int x=xx;
            int y=yy;
            
            if(dir==0){
                x++;
            }
            else if(dir==1){
                y++;
            }
            else if(dir==2){
                x--;
            }
            else{
                y--;
            }
            if(x<0 || x>=w || y<0 || y>=h){
                dir=dir+1;
                dir%=4;
                num++;
                continue;

            }
            xx=x;
            yy=y;
        }

    }
    
    vector<int> getPos() {
        return {xx,yy};
    }
    
    string getDir() {
        if(dir==0) return "East";
        else if(dir==1) return "North";
        else if(dir==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */