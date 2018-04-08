#ifndef FromRightPos_ToLeftScalePath_Part2_H
#define FromRightPos_ToLeftScalePath_Part2_H

#include "TrajectoryPath.h"

class FromRightPos_ToLeftScalePath_Part2 : TrajectoryPath {

public:
	static TrajectoryPath* GetInstance();
	static FromRightPos_ToLeftScalePath_Part2 *m_instance;
	int GetIndexLength();
	double GetStartHeading();
	double GetEndHeading();
	double GetTimeLength();
	double GetDT();
	double* GetLeftTrajectoryArray(int index);
	double* GetRightTrajectoryArray(int index);
	double GetLeftPosition(int index);
	double GetLeftVelocity(int index);
	double GetLeftAcceleration(int index);
	double GetRightPosition(int index);
	double GetRightVelocity(int index);
	double GetRightAcceleration(int index);
	double GetHeading(int index);
	double GetX(int index);
	double GetY(int index);

private:
	FromRightPos_ToLeftScalePath_Part2();
	int num_index = 187;
	double left_wheel[187][8] ={ 
	{0.753, 75.697, 69.720, 6972.037, 0.000, 0.010, 139.652, 7.450},
	{1.510, 75.687, -0.996, -7071.658, 0.000, 0.010, 140.409, 7.450},
	{2.272, 76.142, 45.455, 4645.141, 0.001, 0.010, 141.171, 7.451},
	{3.038, 76.593, 45.107, -34.803, 0.002, 0.010, 141.937, 7.452},
	{3.808, 77.040, 44.711, -39.659, 0.002, 0.010, 142.707, 7.453},
	{4.583, 77.483, 44.263, -44.731, 0.004, 0.010, 143.482, 7.455},
	{5.362, 77.920, 43.763, -50.048, 0.005, 0.010, 144.261, 7.459},
	{6.146, 78.352, 43.206, -55.633, 0.006, 0.010, 145.044, 7.463},
	{6.933, 78.778, 42.591, -61.517, 0.008, 0.010, 145.832, 7.469},
	{7.725, 79.197, 41.914, -67.725, 0.010, 0.010, 146.624, 7.476},
	{8.522, 79.609, 41.171, -74.298, 0.012, 0.010, 147.420, 7.485},
	{9.322, 80.013, 40.358, -81.265, 0.015, 0.010, 148.220, 7.495},
	{10.126, 80.407, 39.472, -88.668, 0.017, 0.010, 149.024, 7.508},
	{10.934, 80.792, 38.506, -96.547, 0.020, 0.010, 149.832, 7.523},
	{11.745, 81.167, 37.457, -104.947, 0.023, 0.010, 150.643, 7.541},
	{12.561, 81.530, 36.318, -113.922, 0.027, 0.010, 151.459, 7.561},
	{13.379, 81.881, 35.082, -123.512, 0.030, 0.010, 152.277, 7.584},
	{14.202, 82.218, 33.745, -133.789, 0.034, 0.010, 153.099, 7.611},
	{15.027, 82.541, 32.297, -144.794, 0.039, 0.010, 153.924, 7.641},
	{15.855, 82.849, 30.730, -156.622, 0.043, 0.010, 154.751, 7.675},
	{16.687, 83.139, 29.037, -169.306, 0.048, 0.010, 155.582, 7.713},
	{17.521, 83.411, 27.208, -182.945, 0.054, 0.010, 156.415, 7.756},
	{18.358, 83.663, 25.232, -197.608, 0.059, 0.010, 157.250, 7.803},
	{19.197, 83.894, 23.098, -213.373, 0.065, 0.010, 158.088, 7.855},
	{20.038, 84.102, 20.795, -230.330, 0.072, 0.010, 158.927, 7.913},
	{20.880, 84.285, 18.309, -248.553, 0.078, 0.010, 159.767, 7.976},
	{21.725, 84.442, 15.628, -268.131, 0.086, 0.010, 160.609, 8.045},
	{22.571, 84.569, 12.736, -289.149, 0.093, 0.010, 161.451, 8.121},
	{23.417, 84.665, 9.620, -311.674, 0.102, 0.010, 162.294, 8.203},
	{24.264, 84.728, 6.262, -335.765, 0.110, 0.010, 163.136, 8.293},
	{25.112, 84.754, 2.647, -361.475, 0.120, 0.010, 163.978, 8.390},
	{25.959, 84.742, -1.241, -388.811, 0.129, 0.010, 164.819, 8.495},
	{26.806, 84.688, -5.418, -417.763, 0.140, 0.010, 165.658, 8.609},
	{27.652, 84.589, -9.901, -448.245, 0.151, 0.010, 166.495, 8.731},
	{28.497, 84.442, -14.702, -480.130, 0.163, 0.010, 167.329, 8.863},
	{29.339, 84.243, -19.834, -513.168, 0.175, 0.010, 168.160, 9.005},
	{30.179, 83.990, -25.304, -547.007, 0.188, 0.010, 168.986, 9.156},
	{31.016, 83.679, -31.115, -581.141, 0.202, 0.010, 169.807, 9.319},
	{31.849, 83.307, -37.264, -614.823, 0.217, 0.010, 170.621, 9.492},
	{32.678, 82.869, -43.735, -647.130, 0.233, 0.010, 171.429, 9.677},
	{33.501, 82.364, -50.502, -676.726, 0.250, 0.010, 172.229, 9.874},
	{34.319, 81.789, -57.522, -701.998, 0.268, 0.010, 173.020, 10.083},
	{35.130, 81.142, -64.730, -720.787, 0.286, 0.010, 173.800, 10.305},
	{35.935, 80.421, -72.035, -730.503, 0.306, 0.010, 174.569, 10.540},
	{36.731, 79.628, -79.314, -727.877, 0.328, 0.010, 175.326, 10.788},
	{37.519, 78.764, -86.405, -709.091, 0.350, 0.010, 176.069, 11.050},
	{38.297, 77.833, -93.101, -669.679, 0.374, 0.010, 176.797, 11.325},
	{39.065, 76.842, -99.148, -604.621, 0.399, 0.010, 177.509, 11.615},
	{39.823, 75.799, -104.233, -508.553, 0.426, 0.010, 178.203, 11.918},
	{40.571, 74.719, -107.994, -376.076, 0.453, 0.010, 178.879, 12.236},
	{41.307, 73.619, -110.016, -202.236, 0.483, 0.010, 179.536, 12.568},
	{42.032, 72.521, -109.849, 16.739, 0.514, 0.010, 180.174, 12.915},
	{42.746, 71.451, -107.023, 282.557, 0.546, 0.010, 180.790, 13.276},
	{43.451, 70.440, -101.085, 593.839, 0.580, 0.010, 181.386, 13.651},
	{44.146, 69.523, -91.634, 945.058, 0.614, 0.010, 181.961, 14.042},
	{44.833, 68.740, -78.377, 1325.753, 0.651, 0.010, 182.516, 14.448},
	{45.515, 68.128, -61.176, 1720.095, 0.688, 0.010, 183.050, 14.871},
	{46.192, 67.727, -40.102, 2107.367, 0.726, 0.010, 183.565, 15.311},
	{46.867, 67.456, -27.084, 1301.796, 0.764, 0.010, 184.061, 15.768},
	{47.539, 67.260, -19.635, 744.937, 0.803, 0.010, 184.537, 16.243},
	{48.212, 67.271, 1.109, 2074.424, 0.842, 0.010, 184.995, 16.736},
	{48.888, 67.578, 30.692, 2958.272, 0.881, 0.010, 185.435, 17.249},
	{49.569, 68.171, 59.365, 2867.269, 0.919, 0.010, 185.858, 17.783},
	{50.260, 69.033, 86.181, 2681.626, 0.957, 0.010, 186.267, 18.340},
	{50.961, 70.137, 110.348, 2416.696, 0.993, 0.010, 186.660, 18.920},
	{51.676, 71.449, 131.280, 2093.161, 1.029, 0.010, 187.040, 19.526},
	{52.405, 72.936, 148.621, 1734.157, 1.063, 0.010, 187.405, 20.157},
	{53.151, 74.558, 162.245, 1362.427, 1.096, 0.010, 187.756, 20.815},
	{53.913, 76.280, 172.226, 998.045, 1.128, 0.010, 188.094, 21.499},
	{54.694, 78.068, 178.795, 656.923, 1.158, 0.010, 188.418, 22.209},
	{55.493, 79.891, 182.297, 350.228, 1.187, 0.010, 188.727, 22.945},
	{56.310, 81.723, 183.142, 84.479, 1.214, 0.010, 189.023, 23.707},
	{57.146, 83.540, 181.764, -137.816, 1.240, 0.010, 189.304, 24.494},
	{57.999, 85.326, 178.591, -317.286, 1.265, 0.010, 189.571, 25.304},
	{58.869, 87.066, 174.023, -456.774, 1.288, 0.010, 189.824, 26.138},
	{59.757, 88.751, 168.419, -560.471, 1.309, 0.010, 190.062, 26.992},
	{60.661, 90.371, 162.086, -633.233, 1.330, 0.010, 190.287, 27.868},
	{61.580, 91.924, 155.286, -680.048, 1.349, 0.010, 190.498, 28.763},
	{62.514, 93.407, 148.229, -705.700, 1.367, 0.010, 190.695, 29.676},
	{63.462, 94.817, 141.084, -714.525, 1.384, 0.010, 190.879, 30.606},
	{64.424, 96.157, 133.980, -710.350, 1.399, 0.010, 191.051, 31.552},
	{65.398, 97.427, 127.016, -696.402, 1.414, 0.010, 191.210, 32.513},
	{66.384, 98.630, 120.262, -675.390, 1.428, 0.010, 191.357, 33.488},
	{67.382, 99.768, 113.767, -649.502, 1.441, 0.010, 191.493, 34.477},
	{68.390, 100.843, 107.562, -620.476, 1.453, 0.010, 191.618, 35.477},
	{69.409, 101.860, 101.665, -589.703, 1.464, 0.010, 191.732, 36.489},
	{70.437, 102.821, 96.083, -558.216, 1.474, 0.010, 191.837, 37.512},
	{71.475, 103.729, 90.815, -526.829, 1.484, 0.010, 191.932, 38.545},
	{72.520, 104.588, 85.854, -496.124, 1.493, 0.010, 192.018, 39.588},
	{73.574, 105.399, 81.189, -466.522, 1.501, 0.010, 192.096, 40.639},
	{74.636, 106.167, 76.805, -438.327, 1.509, 0.010, 192.166, 41.698},
	{75.705, 106.894, 72.688, -411.727, 1.516, 0.010, 192.229, 42.765},
	{76.781, 107.583, 68.819, -386.851, 1.522, 0.010, 192.285, 43.840},
	{77.863, 108.234, 65.182, -363.756, 1.528, 0.010, 192.334, 44.921},
	{78.952, 108.852, 61.757, -342.472, 1.534, 0.010, 192.377, 46.008},
	{80.046, 109.437, 58.527, -322.987, 1.539, 0.010, 192.415, 47.102},
	{81.146, 109.992, 55.475, -305.274, 1.543, 0.010, 192.447, 48.202},
	{82.251, 110.518, 52.582, -289.297, 1.548, 0.010, 192.475, 49.306},
	{83.361, 111.016, 49.832, -275.001, 1.551, 0.010, 192.498, 50.416},
	{84.476, 111.488, 47.208, -262.332, 1.555, 0.010, 192.518, 51.531},
	{85.596, 111.935, 44.696, -251.238, 1.558, 0.010, 192.534, 52.650},
	{86.719, 112.358, 42.279, -241.658, 1.561, 0.010, 192.547, 53.774},
	{87.847, 112.757, 39.944, -233.537, 1.563, 0.010, 192.557, 54.901},
	{88.978, 113.134, 37.676, -226.823, 1.565, 0.010, 192.565, 56.033},
	{90.113, 113.489, 35.461, -221.464, 1.567, 0.010, 192.570, 57.168},
	{91.251, 113.822, 33.287, -217.410, 1.568, 0.010, 192.574, 58.306},
	{92.393, 114.133, 31.141, -214.611, 1.570, 0.010, 192.575, 59.447},
	{93.537, 114.423, 29.011, -213.025, 1.571, 0.010, 192.576, 60.591},
	{94.684, 114.692, 26.885, -212.600, 1.572, 0.010, 192.575, 61.738},
	{95.833, 114.939, 24.752, -213.292, 1.572, 0.010, 192.574, 62.888},
	{96.985, 115.165, 22.601, -215.050, 1.573, 0.010, 192.572, 64.039},
	{98.138, 115.370, 20.423, -217.822, 1.573, 0.010, 192.570, 65.193},
	{99.294, 115.552, 18.207, -221.552, 1.573, 0.010, 192.567, 66.348},
	{100.451, 115.711, 15.946, -226.178, 1.573, 0.010, 192.564, 67.506},
	{101.610, 115.848, 13.629, -231.630, 1.573, 0.010, 192.561, 68.664},
	{102.769, 115.960, 11.251, -237.831, 1.573, 0.010, 192.559, 69.824},
	{103.930, 116.048, 8.804, -244.691, 1.573, 0.010, 192.557, 70.984},
	{105.091, 116.111, 6.283, -252.111, 1.572, 0.010, 192.554, 72.145},
	{106.252, 116.148, 3.683, -259.979, 1.572, 0.010, 192.553, 73.307},
	{107.414, 116.158, 1.002, -268.166, 1.572, 0.010, 192.552, 74.468},
	{108.575, 116.140, -1.764, -276.529, 1.571, 0.010, 192.551, 75.630},
	{109.736, 116.094, -4.613, -284.908, 1.571, 0.010, 192.550, 76.791},
	{110.896, 116.019, -7.544, -293.126, 1.571, 0.010, 192.550, 77.951},
	{112.055, 115.913, -10.554, -300.988, 1.571, 0.010, 192.550, 79.110},
	{113.213, 115.781, -13.212, -265.781, 1.571, 0.010, 192.550, 80.268},
	{114.371, 115.734, -4.694, 851.807, 1.571, 0.010, 192.550, 81.425},
	{115.528, 115.732, -0.231, 446.304, 1.571, 0.010, 192.550, 82.582},
	{116.685, 115.730, -0.202, 2.892, 1.571, 0.010, 192.550, 83.740},
	{117.842, 115.728, -0.174, 2.772, 1.571, 0.010, 192.550, 84.897},
	{119.000, 115.726, -0.147, 2.653, 1.571, 0.010, 192.551, 86.054},
	{120.157, 115.725, -0.122, 2.533, 1.571, 0.010, 192.551, 87.211},
	{121.314, 115.724, -0.098, 2.414, 1.571, 0.010, 192.551, 88.369},
	{122.471, 115.723, -0.075, 2.294, 1.571, 0.010, 192.551, 89.526},
	{123.629, 115.723, -0.053, 2.175, 1.571, 0.010, 192.551, 90.683},
	{124.786, 115.723, -0.033, 2.055, 1.571, 0.010, 192.551, 91.840},
	{125.943, 115.722, -0.013, 1.935, 1.571, 0.010, 192.551, 92.998},
	{127.100, 115.723, 0.005, 1.816, 1.571, 0.010, 192.551, 94.155},
	{128.258, 115.723, 0.022, 1.696, 1.571, 0.010, 192.551, 95.312},
	{129.415, 115.723, 0.038, 1.577, 1.571, 0.010, 192.551, 96.469},
	{130.570, 115.564, -15.876, -1591.338, 1.571, 0.010, 192.551, 97.625},
	{131.721, 115.057, -50.720, -3484.374, 1.571, 0.010, 192.551, 98.776},
	{132.865, 114.361, -69.637, -1891.786, 1.571, 0.010, 192.551, 99.919},
	{134.001, 113.664, -69.628, 0.914, 1.571, 0.010, 192.551, 101.056},
	{135.131, 112.968, -69.621, 0.766, 1.571, 0.010, 192.551, 102.185},
	{136.254, 112.272, -69.614, 0.625, 1.571, 0.010, 192.551, 103.308},
	{137.369, 111.576, -69.610, 0.491, 1.571, 0.010, 192.550, 104.424},
	{138.478, 110.880, -69.606, 0.364, 1.571, 0.010, 192.550, 105.533},
	{139.580, 110.184, -69.603, 0.245, 1.571, 0.010, 192.550, 106.635},
	{140.675, 109.488, -69.602, 0.131, 1.571, 0.010, 192.550, 107.729},
	{141.763, 108.792, -69.602, 0.024, 1.571, 0.010, 192.550, 108.817},
	{142.844, 108.096, -69.603, -0.076, 1.571, 0.010, 192.550, 109.898},
	{143.918, 107.400, -69.604, -0.171, 1.571, 0.010, 192.550, 110.972},
	{144.985, 106.704, -69.607, -0.260, 1.571, 0.010, 192.550, 112.039},
	{146.045, 106.008, -69.610, -0.343, 1.571, 0.010, 192.550, 113.099},
	{147.098, 105.312, -69.615, -0.420, 1.571, 0.010, 192.550, 114.153},
	{148.144, 104.615, -69.619, -0.492, 1.571, 0.010, 192.550, 115.199},
	{149.183, 103.919, -69.625, -0.559, 1.571, 0.010, 192.550, 116.238},
	{150.216, 103.223, -69.631, -0.621, 1.571, 0.010, 192.549, 117.270},
	{151.241, 102.526, -69.638, -0.677, 1.571, 0.010, 192.549, 118.295},
	{152.259, 101.830, -69.645, -0.729, 1.571, 0.010, 192.549, 119.314},
	{153.271, 101.133, -69.653, -0.777, 1.571, 0.010, 192.549, 120.325},
	{154.275, 100.437, -69.661, -0.820, 1.571, 0.010, 192.549, 121.329},
	{155.272, 99.740, -69.670, -0.858, 1.571, 0.010, 192.549, 122.327},
	{156.263, 99.043, -69.679, -0.893, 1.571, 0.010, 192.549, 123.317},
	{157.246, 98.346, -69.688, -0.923, 1.571, 0.010, 192.549, 124.301},
	{158.223, 97.649, -69.698, -0.949, 1.571, 0.010, 192.549, 125.277},
	{159.192, 96.952, -69.707, -0.972, 1.571, 0.010, 192.549, 126.247},
	{160.155, 96.255, -69.717, -0.991, 1.571, 0.010, 192.549, 127.209},
	{161.110, 95.558, -69.727, -1.007, 1.571, 0.010, 192.549, 128.165},
	{162.059, 94.861, -69.737, -1.019, 1.571, 0.010, 192.549, 129.113},
	{163.001, 94.163, -69.748, -1.028, 1.571, 0.010, 192.549, 130.055},
	{163.935, 93.466, -69.758, -1.034, 1.571, 0.010, 192.549, 130.990},
	{164.863, 92.768, -69.768, -1.037, 1.571, 0.010, 192.549, 131.917},
	{165.784, 92.070, -69.779, -1.037, 1.571, 0.010, 192.549, 132.838},
	{166.697, 91.372, -69.789, -1.034, 1.571, 0.010, 192.549, 133.752},
	{167.604, 90.674, -69.799, -1.029, 1.571, 0.010, 192.550, 134.659},
	{168.504, 89.976, -69.810, -1.021, 1.571, 0.010, 192.550, 135.558},
	{169.397, 89.278, -69.820, -1.011, 1.571, 0.010, 192.550, 136.451},
	{170.282, 88.580, -69.830, -0.998, 1.571, 0.010, 192.550, 137.337},
	{171.161, 87.881, -69.840, -0.984, 1.571, 0.010, 192.550, 138.216},
	{172.033, 87.183, -69.849, -0.967, 1.571, 0.010, 192.550, 139.088},
	{172.898, 86.484, -69.859, -0.948, 1.571, 0.010, 192.550, 139.952},
	{172.947, 4.879, -8160.459, -809060.076, 1.571, 0.010, 192.550, 140.001},
	{172.947, 0.000, -487.948, 767251.132, 1.571, 0.010, 192.550, 140.001},
	{172.947, 0.000, 0.000, 48794.816, 1.571, 0.010, 192.550, 140.001},
	{172.947, 0.000, 0.000, 0.000, 1.571, 0.010, 192.550, 140.001},
	{172.947, 0.000, 0.000, 0.000, 1.571, 0.010, 192.550, 140.001}};
	double right_wheel[187][8] ={ 
	{0.753, 75.697, 69.720, 6972.037, 0.000, 0.010, 139.655, -17.450},
	{1.518, 76.404, 70.717, 99.616, 0.000, 0.010, 140.419, -17.450},
	{2.291, 77.344, 93.985, 2326.891, 0.001, 0.010, 141.192, -17.449},
	{3.074, 78.288, 94.333, 34.798, 0.002, 0.010, 141.975, -17.448},
	{3.866, 79.235, 94.730, 39.652, 0.002, 0.010, 142.767, -17.447},
	{4.668, 80.187, 95.177, 44.726, 0.004, 0.010, 143.569, -17.444},
	{5.479, 81.143, 95.678, 50.041, 0.005, 0.010, 144.381, -17.441},
	{6.301, 82.106, 96.234, 55.626, 0.006, 0.010, 145.202, -17.437},
	{7.131, 83.074, 96.849, 61.506, 0.008, 0.010, 146.032, -17.431},
	{7.972, 84.049, 97.526, 67.719, 0.010, 0.010, 146.873, -17.423},
	{8.822, 85.032, 98.269, 74.287, 0.012, 0.010, 147.723, -17.414},
	{9.682, 86.023, 99.082, 81.255, 0.015, 0.010, 148.583, -17.402},
	{10.553, 87.023, 99.968, 88.656, 0.017, 0.010, 149.453, -17.388},
	{11.433, 88.032, 100.933, 96.535, 0.020, 0.010, 150.334, -17.372},
	{12.323, 89.052, 101.983, 104.935, 0.023, 0.010, 151.224, -17.353},
	{13.224, 90.083, 103.122, 113.901, 0.027, 0.010, 152.124, -17.330},
	{14.136, 91.127, 104.357, 123.498, 0.030, 0.010, 153.035, -17.304},
	{15.057, 92.184, 105.694, 133.764, 0.034, 0.010, 153.957, -17.274},
	{15.990, 93.255, 107.142, 144.784, 0.039, 0.010, 154.889, -17.240},
	{16.933, 94.342, 108.708, 156.586, 0.043, 0.010, 155.831, -17.201},
	{17.888, 95.446, 110.401, 169.282, 0.048, 0.010, 156.785, -17.158},
	{18.853, 96.568, 112.230, 182.915, 0.054, 0.010, 157.749, -17.108},
	{19.831, 97.710, 114.206, 197.572, 0.059, 0.010, 158.725, -17.053},
	{20.819, 98.874, 116.339, 213.336, 0.065, 0.010, 159.712, -16.992},
	{21.820, 100.060, 118.642, 230.280, 0.072, 0.010, 160.710, -16.923},
	{22.833, 101.272, 121.127, 248.503, 0.078, 0.010, 161.720, -16.847},
	{23.858, 102.510, 123.808, 268.079, 0.086, 0.010, 162.741, -16.763},
	{24.895, 103.777, 126.699, 289.083, 0.093, 0.010, 163.775, -16.670},
	{25.946, 105.075, 129.815, 311.597, 0.102, 0.010, 164.821, -16.568},
	{27.010, 106.406, 133.171, 335.684, 0.110, 0.010, 165.879, -16.456},
	{28.088, 107.774, 136.785, 361.378, 0.120, 0.010, 166.949, -16.332},
	{29.180, 109.181, 140.672, 388.707, 0.129, 0.010, 168.033, -16.196},
	{30.286, 110.630, 144.849, 417.636, 0.140, 0.010, 169.129, -16.048},
	{31.407, 112.123, 149.330, 448.110, 0.151, 0.010, 170.238, -15.886},
	{32.544, 113.664, 154.129, 479.968, 0.163, 0.010, 171.361, -15.708},
	{33.697, 115.257, 159.259, 512.989, 0.175, 0.010, 172.497, -15.515},
	{34.866, 116.904, 164.727, 546.809, 0.188, 0.010, 173.647, -15.303},
	{36.052, 118.609, 170.536, 580.897, 0.202, 0.010, 174.811, -15.073},
	{37.255, 120.376, 176.682, 614.579, 0.217, 0.010, 175.988, -14.823},
	{38.478, 122.208, 183.150, 646.817, 0.233, 0.010, 177.179, -14.550},
	{39.719, 124.107, 189.914, 676.407, 0.250, 0.010, 178.384, -14.253},
	{40.979, 126.076, 196.931, 701.613, 0.268, 0.010, 179.603, -13.931},
	{42.261, 128.117, 204.134, 720.391, 0.286, 0.010, 180.836, -13.580},
	{43.563, 130.232, 211.435, 730.030, 0.306, 0.010, 182.081, -13.200},
	{44.887, 132.419, 218.709, 727.382, 0.328, 0.010, 183.339, -12.787},
	{46.234, 134.677, 225.794, 708.558, 0.350, 0.010, 184.610, -12.340},
	{47.604, 137.002, 232.485, 669.099, 0.374, 0.010, 185.891, -11.855},
	{48.998, 139.387, 238.525, 604.021, 0.399, 0.010, 187.182, -11.329},
	{50.416, 141.823, 243.605, 507.953, 0.426, 0.010, 188.481, -10.761},
	{51.859, 144.297, 247.360, 375.479, 0.453, 0.010, 189.787, -10.147},
	{53.327, 146.790, 249.377, 201.681, 0.483, 0.010, 191.097, -9.485},
	{54.820, 149.282, 249.204, -17.212, 0.514, 0.010, 192.409, -8.772},
	{56.337, 151.746, 246.375, -282.911, 0.546, 0.010, 193.718, -8.005},
	{57.879, 154.151, 240.435, -594.013, 0.580, 0.010, 195.022, -7.183},
	{59.443, 156.460, 230.985, -945.028, 0.614, 0.010, 196.316, -6.303},
	{61.030, 158.638, 217.731, -1325.435, 0.651, 0.010, 197.596, -5.366},
	{62.636, 160.643, 200.536, -1719.491, 0.688, 0.010, 198.856, -4.369},
	{64.260, 162.438, 179.471, -2106.425, 0.726, 0.010, 200.091, -3.315},
	{65.897, 163.703, 126.553, -5291.827, 0.764, 0.010, 201.294, -2.205},
	{67.539, 164.197, 49.412, -7714.077, 0.803, 0.010, 202.457, -1.045},
	{69.181, 164.186, -1.109, -5052.095, 0.842, 0.010, 203.574, 0.158},
	{70.820, 163.880, -30.674, -2956.495, 0.881, 0.010, 204.641, 1.402},
	{72.453, 163.286, -59.329, -2865.577, 0.919, 0.010, 205.656, 2.681},
	{74.077, 162.425, -86.130, -2680.107, 0.957, 0.010, 206.617, 3.991},
	{75.690, 161.322, -110.285, -2415.413, 0.993, 0.010, 207.522, 5.326},
	{77.290, 160.010, -131.206, -2092.157, 1.029, 0.010, 208.371, 6.682},
	{78.876, 158.525, -148.541, -1733.445, 1.063, 0.010, 209.166, 8.054},
	{80.445, 156.903, -162.161, -1362.005, 1.096, 0.010, 209.905, 9.438},
	{81.997, 155.182, -172.139, -997.879, 1.128, 0.010, 210.592, 10.829},
	{83.531, 153.395, -178.709, -656.987, 1.158, 0.010, 211.228, 12.225},
	{85.046, 151.572, -182.214, -350.469, 1.187, 0.010, 211.816, 13.622},
	{86.544, 149.742, -183.063, -84.856, 1.214, 0.010, 212.357, 15.018},
	{88.023, 147.925, -181.689, 137.342, 1.240, 0.010, 212.856, 16.411},
	{89.484, 146.140, -178.522, 316.756, 1.265, 0.010, 213.313, 17.799},
	{90.928, 144.400, -173.959, 456.213, 1.288, 0.010, 213.732, 19.181},
	{92.355, 142.716, -168.360, 559.906, 1.309, 0.010, 214.116, 20.556},
	{93.766, 141.096, -162.034, 632.679, 1.330, 0.010, 214.467, 21.922},
	{95.162, 139.544, -155.238, 679.523, 1.349, 0.010, 214.787, 23.281},
	{96.542, 138.062, -148.186, 705.200, 1.367, 0.010, 215.078, 24.630},
	{97.909, 136.651, -141.046, 714.071, 1.384, 0.010, 215.344, 25.970},
	{99.262, 135.312, -133.946, 709.924, 1.399, 0.010, 215.585, 27.302},
	{100.603, 134.042, -126.986, 696.024, 1.414, 0.010, 215.804, 28.624},
	{101.931, 132.840, -120.236, 675.047, 1.428, 0.010, 216.003, 29.938},
	{103.248, 131.702, -113.744, 649.187, 1.441, 0.010, 216.182, 31.243},
	{104.554, 130.627, -107.542, 620.208, 1.453, 0.010, 216.344, 32.539},
	{105.850, 129.610, -101.647, 589.451, 1.464, 0.010, 216.490, 33.827},
	{107.137, 128.650, -96.067, 558.002, 1.474, 0.010, 216.620, 35.106},
	{108.414, 127.742, -90.801, 526.636, 1.484, 0.010, 216.738, 36.379},
	{109.683, 126.883, -85.841, 495.949, 1.493, 0.010, 216.842, 37.643},
	{110.944, 126.072, -81.178, 466.373, 1.501, 0.010, 216.936, 38.900},
	{112.197, 125.304, -76.796, 438.191, 1.509, 0.010, 217.018, 40.151},
	{113.443, 124.577, -72.680, 411.611, 1.516, 0.010, 217.091, 41.394},
	{114.682, 123.889, -68.812, 386.745, 1.522, 0.010, 217.155, 42.631},
	{115.914, 123.237, -65.176, 363.665, 1.528, 0.010, 217.211, 43.863},
	{117.140, 122.619, -61.752, 342.388, 1.534, 0.010, 217.260, 45.088},
	{118.360, 122.034, -58.523, 322.914, 1.539, 0.010, 217.302, 46.307},
	{119.575, 121.479, -55.470, 305.212, 1.543, 0.010, 217.338, 47.522},
	{120.785, 120.954, -52.578, 289.239, 1.548, 0.010, 217.368, 48.731},
	{121.989, 120.455, -49.829, 274.949, 1.551, 0.010, 217.394, 49.935},
	{123.189, 119.983, -47.206, 262.289, 1.555, 0.010, 217.415, 51.135},
	{124.384, 119.536, -44.694, 251.198, 1.558, 0.010, 217.432, 52.330},
	{125.576, 119.114, -42.277, 241.622, 1.561, 0.010, 217.446, 53.521},
	{126.763, 118.714, -39.942, 233.506, 1.563, 0.010, 217.456, 54.708},
	{127.946, 118.337, -37.674, 226.796, 1.565, 0.010, 217.464, 55.891},
	{129.126, 117.983, -35.460, 221.440, 1.567, 0.010, 217.470, 57.071},
	{130.302, 117.650, -33.286, 217.388, 1.568, 0.010, 217.473, 58.248},
	{131.476, 117.339, -31.140, 214.595, 1.570, 0.010, 217.475, 59.421},
	{132.646, 117.049, -29.010, 213.009, 1.571, 0.010, 217.476, 60.592},
	{133.814, 116.780, -26.884, 212.587, 1.572, 0.010, 217.475, 61.759},
	{134.979, 116.532, -24.751, 213.281, 1.572, 0.010, 217.474, 62.925},
	{136.143, 116.306, -22.601, 215.041, 1.573, 0.010, 217.472, 64.088},
	{137.304, 116.102, -20.423, 217.815, 1.573, 0.010, 217.470, 65.249},
	{138.463, 115.920, -18.207, 221.547, 1.573, 0.010, 217.467, 66.408},
	{139.620, 115.760, -15.946, 226.174, 1.573, 0.010, 217.464, 67.566},
	{140.777, 115.624, -13.629, 231.627, 1.573, 0.010, 217.461, 68.722},
	{141.932, 115.512, -11.251, 237.829, 1.573, 0.010, 217.459, 69.877},
	{143.086, 115.424, -8.804, 244.690, 1.573, 0.010, 217.456, 71.031},
	{144.240, 115.361, -6.283, 252.112, 1.572, 0.010, 217.454, 72.185},
	{145.393, 115.324, -3.683, 259.980, 1.572, 0.010, 217.453, 73.338},
	{146.546, 115.314, -1.002, 268.167, 1.572, 0.010, 217.452, 74.491},
	{147.699, 115.332, 1.764, 276.530, 1.571, 0.010, 217.451, 75.645},
	{148.853, 115.378, 4.613, 284.909, 1.571, 0.010, 217.450, 76.798},
	{150.008, 115.453, 7.544, 293.127, 1.571, 0.010, 217.450, 77.953},
	{151.163, 115.559, 10.554, 300.987, 1.571, 0.010, 217.450, 79.108},
	{152.320, 115.691, 13.212, 265.780, 1.571, 0.010, 217.450, 80.265},
	{153.477, 115.738, 4.694, -851.809, 1.571, 0.010, 217.450, 81.423},
	{154.635, 115.740, 0.231, -446.305, 1.571, 0.010, 217.450, 82.580},
	{155.792, 115.742, 0.202, -2.892, 1.571, 0.010, 217.450, 83.738},
	{156.950, 115.744, 0.174, -2.772, 1.571, 0.010, 217.450, 84.895},
	{158.107, 115.745, 0.147, -2.653, 1.571, 0.010, 217.451, 86.052},
	{159.265, 115.746, 0.122, -2.533, 1.571, 0.010, 217.451, 87.210},
	{160.422, 115.747, 0.098, -2.414, 1.571, 0.010, 217.451, 88.367},
	{161.580, 115.748, 0.075, -2.294, 1.571, 0.010, 217.451, 89.525},
	{162.737, 115.749, 0.053, -2.175, 1.571, 0.010, 217.451, 90.682},
	{163.895, 115.749, 0.033, -2.055, 1.571, 0.010, 217.451, 91.840},
	{165.052, 115.749, 0.013, -1.935, 1.571, 0.010, 217.451, 92.997},
	{166.210, 115.749, -0.005, -1.816, 1.571, 0.010, 217.451, 94.155},
	{167.367, 115.749, -0.022, -1.696, 1.571, 0.010, 217.451, 95.312},
	{168.524, 115.749, -0.038, -1.577, 1.571, 0.010, 217.451, 96.470},
	{169.680, 115.589, -15.983, -1594.579, 1.571, 0.010, 217.451, 97.626},
	{170.831, 115.080, -50.860, -3487.663, 1.571, 0.010, 217.451, 98.776},
	{171.975, 114.382, -69.803, -1894.334, 1.571, 0.010, 217.451, 99.920},
	{173.112, 113.684, -69.812, -0.914, 1.571, 0.010, 217.451, 101.057},
	{174.242, 112.986, -69.820, -0.766, 1.571, 0.010, 217.451, 102.187},
	{175.365, 112.287, -69.826, -0.625, 1.571, 0.010, 217.451, 103.310},
	{176.480, 111.589, -69.831, -0.491, 1.571, 0.010, 217.450, 104.426},
	{177.589, 110.891, -69.835, -0.364, 1.571, 0.010, 217.450, 105.535},
	{178.691, 110.192, -69.837, -0.245, 1.571, 0.010, 217.450, 106.637},
	{179.786, 109.494, -69.839, -0.131, 1.571, 0.010, 217.450, 107.732},
	{180.874, 108.796, -69.839, -0.024, 1.571, 0.010, 217.450, 108.819},
	{181.955, 108.097, -69.838, 0.076, 1.571, 0.010, 217.450, 109.900},
	{183.029, 107.399, -69.836, 0.171, 1.571, 0.010, 217.450, 110.974},
	{184.096, 106.701, -69.834, 0.260, 1.571, 0.010, 217.450, 112.041},
	{185.156, 106.002, -69.830, 0.343, 1.571, 0.010, 217.450, 113.101},
	{186.209, 105.304, -69.826, 0.420, 1.571, 0.010, 217.450, 114.155},
	{187.255, 104.606, -69.821, 0.492, 1.571, 0.010, 217.450, 115.201},
	{188.294, 103.908, -69.816, 0.559, 1.571, 0.010, 217.450, 116.240},
	{189.326, 103.210, -69.809, 0.621, 1.571, 0.010, 217.449, 117.272},
	{190.352, 102.512, -69.803, 0.677, 1.571, 0.010, 217.449, 118.297},
	{191.370, 101.814, -69.795, 0.729, 1.571, 0.010, 217.449, 119.315},
	{192.381, 101.116, -69.788, 0.777, 1.571, 0.010, 217.449, 120.326},
	{193.385, 100.418, -69.779, 0.820, 1.571, 0.010, 217.449, 121.330},
	{194.382, 99.720, -69.771, 0.858, 1.571, 0.010, 217.449, 122.328},
	{195.372, 99.023, -69.762, 0.893, 1.571, 0.010, 217.449, 123.318},
	{196.356, 98.325, -69.753, 0.923, 1.571, 0.010, 217.449, 124.301},
	{197.332, 97.628, -69.743, 0.949, 1.571, 0.010, 217.449, 125.277},
	{198.301, 96.930, -69.733, 0.972, 1.571, 0.010, 217.449, 126.247},
	{199.264, 96.233, -69.724, 0.991, 1.571, 0.010, 217.449, 127.209},
	{200.219, 95.536, -69.713, 1.007, 1.571, 0.010, 217.449, 128.164},
	{201.167, 94.839, -69.703, 1.019, 1.571, 0.010, 217.449, 129.113},
	{202.109, 94.142, -69.693, 1.028, 1.571, 0.010, 217.449, 130.054},
	{203.043, 93.445, -69.683, 1.034, 1.571, 0.010, 217.449, 130.989},
	{203.971, 92.748, -69.672, 1.037, 1.571, 0.010, 217.449, 131.916},
	{204.891, 92.052, -69.662, 1.037, 1.571, 0.010, 217.449, 132.837},
	{205.805, 91.355, -69.652, 1.034, 1.571, 0.010, 217.449, 133.750},
	{206.711, 90.659, -69.641, 1.029, 1.571, 0.010, 217.450, 134.657},
	{207.611, 89.963, -69.631, 1.021, 1.571, 0.010, 217.450, 135.556},
	{208.504, 89.266, -69.621, 1.011, 1.571, 0.010, 217.450, 136.449},
	{209.389, 88.570, -69.611, 0.998, 1.571, 0.010, 217.450, 137.335},
	{210.268, 87.874, -69.601, 0.984, 1.571, 0.010, 217.450, 138.213},
	{211.140, 87.178, -69.592, 0.967, 1.571, 0.010, 217.450, 139.085},
	{212.005, 86.482, -69.582, 0.948, 1.571, 0.010, 217.450, 139.950},
	{212.054, 4.879, -8160.299, -809071.660, 1.571, 0.010, 217.450, 139.999},
	{212.054, 0.000, -487.948, 767235.094, 1.571, 0.010, 217.450, 139.999},
	{212.054, 0.000, 0.000, 48794.768, 1.571, 0.010, 217.450, 139.999},
	{212.054, 0.000, 0.000, 0.000, 1.571, 0.010, 217.450, 139.999},
	{212.054, 0.000, 0.000, 0.000, 1.571, 0.010, 217.450, 139.999}};
};

#endif