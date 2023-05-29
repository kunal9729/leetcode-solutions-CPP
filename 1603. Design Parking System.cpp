class ParkingSystem {
public:
    int big;
    int medium;
    int small;

    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {}

    bool addCar(int carType) {
        return (carType == 1 && big-- > 0) || (carType == 2 && medium-- > 0) || (carType == 3 && small-- > 0);
    }
};


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
