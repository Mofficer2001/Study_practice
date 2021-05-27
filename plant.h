#ifndef PLANT_H_INCLUDED
#define PLANT_H_INCLUDED


#ifdef __cplusplus
extern "C" {
#endif

/** @brief �������� ��������� ������� ���������� ��� ������������. */
typedef double Plant[53];

/** @brief �������������� ��������� ������� ���������� ��� ������������. */
void plant_init(Plant plant);

/**
 * @brief ��������� ���������� ������� ������������.
 * @param kanal ����� ���������.
 * @return �������� ����������.
 */
double plant_measure(int kanal, Plant plant);

/**
 * @brief ������ ����������� ����������� �� ������.
 * @param kanal ����� ���������� (7..10).
 * @param upr �������� ������������ �����������.
 * @param plant ������ ������, ����������� ��������� �������.
 */
void plant_control(int kanal, double upr, Plant plant);

#ifdef __cplusplus
}  /* extern "C" */
#endif


#endif // PLANT_H_INCLUDED
