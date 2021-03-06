#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

class Elevator : public QObject {
public:
    Elevator(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~Elevator() {}
    Q_INVOKABLE static inline quint8 get_capacity() { return capacity; }
    Q_INVOKABLE static inline quint8 get_direction_current() { return direction_current; }
    Q_INVOKABLE static inline quint8 get_direction_planned() { return direction_planned; }
    Q_INVOKABLE static inline qint32 get_floor() { return floor_current; }
    Q_INVOKABLE static inline qreal get_progress() { return progress == 0 ? 0.0 : 1.0 / progress; }
    Q_INVOKABLE static inline quint32 get_time_remain() { return time_remain; }
    Q_INVOKABLE virtual bool get_is_next_stop_down(const qint32 &floor) = 0;
    Q_INVOKABLE virtual bool get_is_next_stop_up(const qint32 &floor) = 0;
    Q_INVOKABLE virtual QString get_next_stop_down() = 0;
    Q_INVOKABLE virtual QString get_next_stop_up() = 0;

public slots:
    virtual void elevator_init(const quint32 &floor_max, const quint32 &floor_min, const quint32 &time_door_move, const quint32 &time_next_floor, const quint32 &time_stop) = 0;
    virtual void update_next_stop_down(const qint32 &next_stop) = 0;
    virtual void update_next_stop_up(const qint32 &next_stop) = 0;

protected:
    static quint8 capacity, direction_current, direction_planned, progress;
    static qint32 floor_current, floor_max, floor_min;
    static quint32 time_door_move, time_next_floor, time_remain, time_stop;

protected slots:
    virtual void elevator_process() = 0;

private:
    Q_OBJECT

signals:
    void elevatorCapacityUpdate();
    void elevatorDirectionUpdate();
    void elevatorDoorClose();
    void elevatorDoorOpen();
    void elevatorFloorUpdate();
    void elevatorNextStopUpdate();
    void elevatorTimeRemainUpdate();
    void elevatorStart();
};

#endif // ELEVATOR_H
