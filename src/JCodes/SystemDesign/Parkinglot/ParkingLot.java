package JCodes.SystemDesign.Parkinglot;

public class ParkingLot {
    private int numberOfLevels;
    private Level[] levels;

    public ParkingLot(int numberOfLevels) {
        this.numberOfLevels = numberOfLevels;
        levels = new Level[numberOfLevels];

        for(int i = 0 ; i < numberOfLevels ; i++) {
            // 30 for now has been hard coded.
            levels[i] = new Level(i , 30);
        }
    }

    public boolean park(Vehicle vehicle) {
        for (Level level : levels) {
            if(level.park(vehicle)) {
                return true;
            }
        }
        return false;
    }
}
