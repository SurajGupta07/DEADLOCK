#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
int bzco[4][2]={{0,0},{69,221},{181,79},{320,300}},c[4],n=3;
int s1x,s1y,s2x,s2y;
void bezierCoefficients(int n,int *c)
{
    int k,i;
    for(k=0;k<=n;k++)
    {
        c[k]=1;
        
        for(i=n;i>=k+1;i--)
            c[k]*=i;
        
            //c[k] = 1 / (1+ exp (i));
        
        for(i=n-k;i>=2;i--)
            c[k]/=i;
        



            /*x <- c(-10:10)
            b = 0 # intercept
            m = 1 # slope
            y <- exp((b + m*x)) / (1 + exp((b + m*x))
            */

           /*
           c[k] = exp((gb + i*gx)) / (1 + exp((gb + i*gx)));
           */
    }
}

void disphelper(int x,int y){
    if(x<y){
        glColor3f(1.0,0.0,0.0);
        glPointSize(7);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
    }
    else if(x>y){
        glColor3f(0.0,1.0,0.0);
        glPointSize(7);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
    }
}

void display1(void)
{
int k;

float x,y,u,blend;

    glClear(GL_COLOR_BUFFER_BIT);

    // To draw points
    glColor3f(1.0,0.0,0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2f(1, 1);
    glVertex2f(319, 1);
    glVertex2f(1, 300);
    glVertex2f(100, 100);


    disphelper(144,73);
disphelper(297,64);
disphelper(204,47);
disphelper(307,111);
disphelper(306,257);
disphelper(62,57);
disphelper(284,231);
disphelper(24,155);
disphelper(59,158);
disphelper(215,7);
disphelper(41,154);
disphelper(251,16);
disphelper(33,130);
disphelper(76,71);
disphelper(116,247);
disphelper(191,122);
disphelper(174,253);
disphelper(127,131);
disphelper(208,213);
disphelper(36,185);
disphelper(291,249);
disphelper(206,103);
disphelper(201,93);
disphelper(234,9);
disphelper(260,30);
disphelper(266,120);
disphelper(189,262);
disphelper(95,273);
disphelper(115,151);
disphelper(275,65);
disphelper(186,192);
disphelper(267,145);
disphelper(23,107);
disphelper(56,110);
disphelper(182,52);
disphelper(303,115);
disphelper(1,10);
disphelper(274,190);
disphelper(295,58);
disphelper(232,156);
disphelper(300,59);
disphelper(184,29);
disphelper(29,176);
disphelper(35,99);
disphelper(271,291);
disphelper(207,97);
disphelper(239,32);
disphelper(79,85);
disphelper(314,142);
disphelper(12,178);
disphelper(11,26);
disphelper(130,279);
disphelper(283,63);
disphelper(255,170);
disphelper(4,23);
disphelper(199,248);
disphelper(67,286);
disphelper(221,282);
disphelper(211,172);
disphelper(94,18);
disphelper(21,260);
disphelper(156,239);
disphelper(101,105);
disphelper(190,267);
disphelper(154,259);
disphelper(317,105);
disphelper(2,108);
disphelper(106,186);
disphelper(282,41);
disphelper(168,3);
disphelper(109,194);
disphelper(53,278);
disphelper(28,292);
disphelper(78,196);
disphelper(25,102);
disphelper(102,82);
disphelper(261,281);
disphelper(197,14);
disphelper(54,17);
disphelper(228,126);
disphelper(256,258);
disphelper(5,162);
disphelper(138,49);
disphelper(320,144);
disphelper(173,44);
disphelper(161,203);
disphelper(103,96);
disphelper(148,1);
disphelper(89,212);
disphelper(318,211);
disphelper(319,222);
disphelper(80,50);
disphelper(172,21);
disphelper(288,141);
disphelper(152,56);
disphelper(90,69);
disphelper(51,219);
disphelper(31,114);
disphelper(203,27);
disphelper(88,91);
disphelper(210,4);
disphelper(176,113);
disphelper(253,144);
disphelper(121,95);
disphelper(254,34);
disphelper(244,246);
disphelper(42,147);
disphelper(104,152);
disphelper(122,88);
disphelper(227,146);
disphelper(49,53);
disphelper(223,116);
disphelper(293,269);
disphelper(58,283);
disphelper(224,225);
disphelper(100,62);
disphelper(278,167);
disphelper(39,43);
disphelper(157,132);
disphelper(44,71);
disphelper(194,280);
disphelper(7,36);
disphelper(216,208);
disphelper(171,210);
disphelper(240,75);
disphelper(259,291);
disphelper(141,45);
disphelper(179,100);
disphelper(32,46);
disphelper(84,300);
disphelper(196,39);
disphelper(71,51);
disphelper(55,299);
disphelper(27,128);
disphelper(30,54);
disphelper(166,70);
disphelper(273,263);
disphelper(165,242);
disphelper(114,296);
disphelper(70,160);
disphelper(68,284);
disphelper(43,19);
disphelper(231,22);
disphelper(289,251);
disphelper(163,11);
disphelper(262,297);
disphelper(52,55);
disphelper(263,166);
disphelper(74,218);
disphelper(159,266);
disphelper(287,291);
disphelper(50,240);
disphelper(117,74);
disphelper(192,169);
disphelper(304,159);
disphelper(249,198);
disphelper(277,150);
disphelper(257,48);
disphelper(153,196);
disphelper(160,171);
disphelper(155,139);
disphelper(93,38);
disphelper(290,94);
disphelper(14,71);
disphelper(245,25);
disphelper(302,173);
disphelper(292,191);
disphelper(296,60);
disphelper(63,140);
disphelper(87,220);
disphelper(125,76);
disphelper(60,143);
disphelper(40,149);
disphelper(164,184);
disphelper(19,148);
disphelper(48,193);
disphelper(185,290);
disphelper(69,243);
disphelper(82,195);
disphelper(81,245);
disphelper(119,137);
disphelper(146,230);
disphelper(107,264);
disphelper(188,89);
disphelper(243,123);
disphelper(217,180);
disphelper(86,216);
disphelper(133,105);
disphelper(279,196);
disphelper(98,109);
disphelper(180,165);
disphelper(57,276);
disphelper(198,189);
disphelper(124,235);
disphelper(200,106);
disphelper(270,201);
disphelper(258,78);
disphelper(97,285);
disphelper(123,13);
disphelper(92,200);
disphelper(105,287);
disphelper(150,20);
disphelper(222,15);
disphelper(3,12);
disphelper(313,125);
disphelper(285,5);
disphelper(276,30);
disphelper(202,274);
disphelper(212,42);
disphelper(22,134);
disphelper(108,244);
disphelper(129,217);
disphelper(219,174);
disphelper(145,275);
disphelper(226,181);
disphelper(18,129);
disphelper(214,255);
disphelper(230,197);
disphelper(132,214);
disphelper(305,232);
disphelper(73,226);
disphelper(110,250);
disphelper(65,110);
disphelper(236,105);
disphelper(15,277);
disphelper(151,254);
disphelper(131,79);
disphelper(311,83);
disphelper(8,81);
disphelper(91,163);
disphelper(99,224);
disphelper(142,207);
disphelper(149,237);
disphelper(118,110);
disphelper(83,80);
disphelper(10,72);
disphelper(167,135);
disphelper(250,271);
disphelper(229,84);
disphelper(233,261);
disphelper(85,95);
disphelper(140,161);
disphelper(13,202);
disphelper(193,35);
disphelper(265,68);
disphelper(272,136);
disphelper(312,291);
disphelper(264,112);
disphelper(38,236);
disphelper(96,127);
disphelper(281,24);
disphelper(169,95);
disphelper(181,187);
disphelper(128,298);
disphelper(246,179);
disphelper(178,90);
disphelper(17,241);
disphelper(237,293);
disphelper(20,6);
disphelper(45,2);
disphelper(218,164);
disphelper(301,37);
disphelper(225,256);
disphelper(147,199);
disphelper(34,28);
disphelper(113,289);
disphelper(135,119);
disphelper(137,8);
disphelper(61,86);
disphelper(309,234);
disphelper(139,121);
disphelper(248,104);
disphelper(177,30);
disphelper(66,228);
disphelper(247,182);
disphelper(112,98);
disphelper(111,144);
disphelper(299,168);
disphelper(75,272);
disphelper(268,215);
disphelper(298,227);
disphelper(213,110);
disphelper(195,238);
disphelper(143,31);
disphelper(136,295);
disphelper(235,67);
disphelper(170,157);
disphelper(175,153);
disphelper(47,40);
disphelper(220,188);
disphelper(72,209);
disphelper(280,138);
disphelper(209,33);
disphelper(46,117);
disphelper(241,268);
disphelper(183,233);
disphelper(242,87);
disphelper(120,221);
disphelper(310,61);
disphelper(252,265);
disphelper(37,92);
disphelper(134,288);
disphelper(162,205);
disphelper(16,66);
disphelper(9,101);
disphelper(6,223);
disphelper(126,270);
disphelper(205,196);
disphelper(238,77);
disphelper(187,183);
disphelper(269,206);
disphelper(286,294);
disphelper(158,175);
disphelper(64,252);
disphelper(308,118);
disphelper(294,204);
disphelper(77,177);
disphelper(315,133);
disphelper(316,229);
disphelper(26,124);
disphelper(110,174);
disphelper(34,281);
disphelper(197,131);
disphelper(17,247);
disphelper(245,158);
disphelper(252,264);
disphelper(318,258);
disphelper(32,24);
disphelper(50,251);
disphelper(212,127);
disphelper(226,99);
disphelper(29,180);
disphelper(308,290);
disphelper(238,104);
disphelper(4,130);
disphelper(313,226);
disphelper(187,27);
disphelper(167,191);
disphelper(108,111);
disphelper(31,162);
disphelper(204,275);
disphelper(52,253);
disphelper(296,26);
disphelper(114,109);
disphelper(12,145);
disphelper(2,20);
disphelper(224,97);
disphelper(285,133);
disphelper(256,92);
disphelper(293,58);
disphelper(157,8);
disphelper(100,170);
disphelper(163,248);
disphelper(219,46);
disphelper(261,297);
disphelper(181,144);
disphelper(139,265);
disphelper(172,163);
disphelper(170,138);
disphelper(129,262);
disphelper(169,134);
disphelper(162,53);
disphelper(9,263);
disphelper(81,9);
disphelper(232,254);
disphelper(14,72);
disphelper(209,166);
disphelper(122,13);
disphelper(291,118);
disphelper(155,77);
disphelper(242,74);
disphelper(316,65);
disphelper(39,178);
disphelper(120,285);
disphelper(148,165);
disphelper(138,73);
disphelper(282,244);
disphelper(90,227);
disphelper(5,60);
disphelper(171,222);
disphelper(271,270);
disphelper(132,292);
disphelper(153,257);
disphelper(140,55);
disphelper(251,193);
disphelper(144,114);
disphelper(272,214);
disphelper(91,210);
disphelper(41,283);
disphelper(202,183);
disphelper(101,25);
disphelper(36,192);
disphelper(240,200);
disphelper(276,1);
disphelper(262,43);
disphelper(146,195);
disphelper(135,76);
disphelper(290,198);
disphelper(104,197);
disphelper(123,176);
disphelper(237,69);
disphelper(58,34);
disphelper(198,84);
disphelper(20,217);
disphelper(63,184);
disphelper(200,98);
disphelper(92,93);
disphelper(103,23);
disphelper(199,119);
disphelper(79,189);
disphelper(6,167);
disphelper(164,203);
disphelper(131,6);
disphelper(43,91);
disphelper(195,201);
disphelper(158,293);
disphelper(259,47);
disphelper(23,215);
disphelper(229,18);
disphelper(233,136);
disphelper(274,171);
disphelper(80,61);
disphelper(106,143);
disphelper(254,44);
disphelper(280,232);
disphelper(265,291);
disphelper(72,146);
disphelper(137,139);
disphelper(83,266);
disphelper(38,108);
disphelper(107,268);
disphelper(178,39);
disphelper(304,273);
disphelper(165,300);
disphelper(19,100);
disphelper(277,211);
disphelper(15,239);
disphelper(180,56);
disphelper(236,238);
disphelper(37,35);
disphelper(230,37);
disphelper(294,255);
disphelper(269,42);
disphelper(67,103);
disphelper(297,216);
disphelper(234,32);
disphelper(218,121);
disphelper(70,59);
disphelper(61,112);
disphelper(65,66);
disphelper(210,243);
disphelper(45,220);
disphelper(286,90);
disphelper(225,113);
disphelper(315,236);
disphelper(57,199);
disphelper(255,150);
disphelper(7,188);
disphelper(192,231);
disphelper(281,172);
disphelper(208,240);
disphelper(8,271);
disphelper(11,78);
disphelper(253,282);
disphelper(260,57);
disphelper(214,284);
disphelper(125,272);
disphelper(94,87);
disphelper(105,152);
disphelper(16,276);
disphelper(1,95);
disphelper(239,31);
disphelper(188,260);
disphelper(3,230);
disphelper(143,148);
disphelper(109,278);
disphelper(176,142);
disphelper(33,70);
disphelper(133,80);
disphelper(189,295);
disphelper(213,17);
disphelper(117,279);
disphelper(194,228);
disphelper(21,151);
disphelper(211,4);
disphelper(215,110);
disphelper(275,128);
disphelper(46,75);
disphelper(270,135);
disphelper(250,64);
disphelper(88,88);
disphelper(85,40);
disphelper(95,141);
disphelper(166,204);
disphelper(62,212);
disphelper(10,206);
disphelper(75,155);
disphelper(220,205);
disphelper(186,223);
disphelper(295,89);
disphelper(13,54);
disphelper(190,296);
disphelper(267,14);
disphelper(134,30);
disphelper(246,82);
disphelper(284,229);
disphelper(283,156);
disphelper(243,168);
disphelper(113,62);
disphelper(292,235);
disphelper(227,21);
disphelper(68,242);
disphelper(161,12);
disphelper(24,115);
disphelper(235,288);
disphelper(30,5);
disphelper(56,157);
disphelper(40,209);
disphelper(96,71);
disphelper(145,10);
disphelper(47,269);
disphelper(97,161);
disphelper(111,250);
disphelper(257,221);
disphelper(273,246);
disphelper(317,79);
disphelper(228,94);
disphelper(69,207);
disphelper(130,213);
disphelper(64,185);
disphelper(77,186);
disphelper(266,181);
disphelper(82,125);
disphelper(309,261);
disphelper(159,33);
disphelper(128,22);
disphelper(302,7);
disphelper(183,194);
disphelper(301,241);
disphelper(136,286);
disphelper(151,289);
disphelper(126,45);
disphelper(320,105);
disphelper(119,190);
disphelper(244,249);
disphelper(299,225);
disphelper(179,83);
disphelper(287,11);
disphelper(121,117);
disphelper(73,52);
disphelper(49,299);
disphelper(279,124);
disphelper(312,182);
disphelper(314,153);
disphelper(184,120);
disphelper(264,202);
disphelper(142,126);
disphelper(177,274);
disphelper(191,51);
disphelper(112,48);
disphelper(231,29);
disphelper(185,259);
disphelper(78,224);
disphelper(193,116);
disphelper(248,219);
disphelper(223,294);
disphelper(247,147);
disphelper(175,233);
disphelper(124,169);
disphelper(168,85);
disphelper(307,106);
disphelper(42,3);
disphelper(201,256);
disphelper(44,16);
disphelper(53,208);
disphelper(173,234);
disphelper(249,149);
disphelper(59,218);
disphelper(141,15);
disphelper(221,277);
disphelper(66,154);
disphelper(149,67);
disphelper(306,287);
disphelper(303,36);
disphelper(278,140);
disphelper(298,63);
disphelper(74,107);
disphelper(60,28);
disphelper(268,164);
disphelper(216,41);
disphelper(196,173);
disphelper(55,102);
disphelper(263,237);
disphelper(160,267);
disphelper(51,49);
disphelper(222,81);
disphelper(28,252);
disphelper(118,298);
disphelper(289,68);
disphelper(93,280);
disphelper(54,123);
disphelper(154,196);
disphelper(84,179);
disphelper(98,137);
disphelper(152,122);
disphelper(182,50);
disphelper(48,177);
disphelper(27,132);
disphelper(288,86);
disphelper(26,38);
disphelper(35,160);
disphelper(71,101);
disphelper(203,96);
disphelper(115,187);
disphelper(76,175);
disphelper(206,19);
disphelper(241,245);
disphelper(150,2);
disphelper(127,129);
disphelper(319,159);







    
        // glVertex2f(80, 34);
        // glVertex2f(85, 24);
        // glVertex2f(78, 24);
        // glVertex2f(46, 35);
        // glVertex2f(67, 47);
        // glVertex2f(85, 26);
        // glVertex2f(78, 68);
        // glVertex2f(86, 56);
        // glVertex2f(82, 54);
        // glVertex2f(56, 69);

        // glVertex2f(32, 34);
        // glVertex2f(24, 24);
        // glVertex2f(27, 47);
        // glVertex2f(36, 26);
        // glVertex2f(25, 68);
        // glVertex2f(38, 54);
        // glVertex2f(27, 69);

        // glVertex2f(24, 87);
        // glVertex2f(27, 94);
        // glVertex2f(25, 82);
        // glVertex2f(27, 87);
        // glVertex2f(16, 84);
        // glVertex2f(13, 69);
        // glVertex2f(16, 56);
        // glVertex2f(13, 24);

        // glVertex2f(48, 35);
        // glVertex2f(38, 96);
        // glVertex2f(36, 84);
        // glVertex2f(32, 67);
        // glVertex2f(48, 79);        
        
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2f(34, 38);
        glVertex2f(46, 35);
        glVertex2f(56, 69);
        glVertex2f(43, 47);

        

    glEnd();
        // Simple try
        // for(int g=10,h=80;g<80,h<150;g++,h++)
        // {    g=g-2;
        //     h=h+3;
        //     glVertex2f(80, g);
        //     h=h-2;
        //     g=g+3;
        // }


    glColor3f(0.0,0.0,1.0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);

    for(u=0;u<1.0;u+=0.001)
    {x=0;y=0;
        for(k=0;k<4;k++)
        {
            blend=c[k]*pow(u,k)*pow(1-u,n-k);
            x+=bzco[k][0]*blend;
            y+=bzco[k][1]*blend;
        }
        glVertex2f(x,y);

    }
    glEnd();

    //moving points
    
    // glBegin(GL_POINTS);
    // glVertex2f(bzco[1][0],bzco[1][1]);
    // glVertex2f(bzco[2][0],bzco[2][1]);
    // glEnd();
    

    glFlush();
    glutSwapBuffers();
}
void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    gluOrtho2D(0.0,320.0,0.0,300.0);
}
void motion(void)
{
    bzco[1][0]+=s1x;
    bzco[1][1]+=s1y;
    bzco[2][0]+=s2x;
    bzco[2][1]+=s2y;
    if(bzco[1][0]<0||bzco[1][0]>320)
    {
        s1x=-s1x;
    }
    if(bzco[1][1]<0||bzco[1][1]>300)
    {
        s1y=-s1y;
    }
    if(bzco[2][0]<0||bzco[2][0]>320)
    {
        s2x=-s2x;
    }
    if(bzco[2][1]<0||bzco[2][1]>300)
    {
        s2y=-s2y;
    }
    glutPostRedisplay();
}
int function()
{
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(320,300);

    glutCreateWindow("Logistic Function");
    glutFullScreen();
    glutDisplayFunc(display1);
//    glutDisplayFunc(display);
    glutIdleFunc(motion);
    myinit();
    bezierCoefficients(n,c);
    s1x=-1;s1y=-1;s2x=-1;s2y=1;
    glutMainLoop();
    return 0;

}

