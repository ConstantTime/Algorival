package JCodes.SystemDesign.Parkinglot;

public class Spot {

    private Vehicle vehicle;
    private SpotSize spotSize;

    public Spot(Vehicle vehicle , SpotSize spotSize) {
        this.vehicle = vehicle;
        this.spotSize = spotSize;
    }

    public Spot(SpotSize spotSize) {
        this.spotSize = spotSize;
    }

    public boolean isAvailable() {
        return null == vehicle;
    }

    public boolean park(Vehicle vehicle) {
        if(isAvailable()) {
            this.vehicle = vehicle;
            return true;
        }

        return false;
    }

    public void removeVehicle() {
        vehicle = null;
    }
}
