# BattleCity
## Scene
控制介面顯示與操作
* Scene()
  * 新增背景
    * 介面長寬 = 600 X 340
    * 黑色部分 = 480 X 320
  * 新增player1
  * 新增基本坦克
* keyPressEvent()
  * 控制player1移動
  * 按下空白鍵時射擊，將IsBulletInScene改為True
* *player1
  * 玩家1
* *bullet1
  * 玩家1的子彈
## Tank
基礎坦克控制
* Tank()
* Rotate()
  * 旋轉
  * 更新Rotation
* Rotation-getter() setter()
  * 儲存旋轉角度
* IsBulletInScene-getter() setter()
  * 判斷子彈是否在畫面上
## BasicTank
基礎敵人
* BasicTank()
  * 建立基礎敵人，大小32 X 32
  * Rotation = 0
  * isChangingDirection = false
  * 建立timer connect到move
* move()
  * 每0.1秒移動4
  * 若超出界線則移動回界線內且轉向
  * 若撞到 water 和 brick 則稍微退後並轉向
  * 轉向機率四個方向相同
* *timer
* isChangingDirection
## Player1
玩家1
* Player1()
  * 建立player1
  * 建立bullet
* *Bullet-getter() setter()
## Bullet
子彈
* Bullet()
  * 建立子彈
  * 建立timer，connect到move
* move()
  * 每0.05秒移動8
  * 碰到邊界時移除，將IsBulletInScene改為false
* Rotate()
  * 旋轉並更新Rotation
* *Parent-getter() setter()
  * 紀錄擁有子彈的Tank
* *timer
* Rotation-getter() setter()
