#ifndef TENNANT_H
#define TENNANT_H

#include <QString>

class Tennant //将要显示的东西
{
public:
    Tennant(QString name,QString Real_estate,QString House_id,QString tel,QString end,QString cycle,int month_rent,QString begin,int Payment_times,QString state);
    Tennant();
    QString name() const ; //返回姓名
    QString Real_estate() const; // 返回房产-房号
    QString tel() const;  // 返回联系电话
    QString end() const; // 返回到租日期
    QString cycle() const;  //返回缴费周期
    QString month_rent() const; //返回每期缴租
    QString ruzhu() const; //返回入住天数
    QString payment_times() const; //返回缴费次数
    QString state() const; //返回缴费情况
    int number();
private:
    QString m_name; //姓名
    QString m_Real_estate; //房产
    QString m_House_id; //房号
    QString m_tel;// 联系电话
    QString m_end; //到租日期
    QString m_cycle;//缴费周期
    int m_month_rent; //每期缴租
    QString m_begin; //开始日期
    int m_ruzhu; //入住天数
    int m_Payment_time; // 缴费次数
    QString m_state;// 缴费情况
};

#endif // TENNANT_H
