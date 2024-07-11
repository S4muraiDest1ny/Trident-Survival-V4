--// Trident Survival v1. [DEV]

	--// Locals
	local camera = game:GetService("Workspace").Camera;
	local Camera = game:GetService("Workspace").Camera
	local Camera = game:GetService("Workspace").CurrentCamera
	local Cam = game:GetService("Workspace").Camera
	local CharcaterMiddle = game:GetService("Workspace").Ignore.LocalCharacter.Middle
	local Mouse = game.Players.LocalPlayer:GetMouse()
	local lighting = game:GetService("Lighting")
	local SoundService = game:GetService("SoundService")
	local Decimals = 2
	local Clock = os.clock()

    
local Camera = game:GetService("Workspace").Camera
local CameraPred = game:GetService("Workspace").CurrentCamera
local Mouse = game.Players.LocalPlayer:GetMouse()
local CharcaterMiddle = game:GetService("Workspace").Ignore.LocalCharacter.Middle
	
--// LPH
if not LPH_OBFUSCATED then
	LPH_JIT = function(...) return ... end
	LPH_JIT_MAX = function(...) return ... end
	LPH_JIT_ULTRA = function(...) return ... end
	LPH_NO_VIRTUALIZE = function(...) return ... end
	LPH_NO_UPVALUES = function(f) return(function(...) return f(...) end) end
	LPH_ENCSTR = function(...) return ... end
	LPH_STRENC = function(...) return ... end
	LPH_HOOK_FIX = function(...) return ... end
	LPH_CRASH = function() return print(debug.traceback()) end
	end;


--// Ui
local Library = loadstring(game:HttpGet('https://raw.githubusercontent.com/BigHacker123/Library.lua/main/Library.lua'))()
local SaveManager = loadstring(game:HttpGet('https://raw.githubusercontent.com/violin-suzutsuki/LinoriaLib/main/addons/SaveManager.lua'))()

--
local Build = "DEV";local Color = "#ffbf00";local Ver =                       "v1"

if Build == "DEV" then Color = '#D17bff' Ver =     "v1" end
local Window = Library:CreateWindow({ Size = UDim2.fromOffset(550, 610),Title = "BALLZ.CC<font color=\"#d17bff\"></font> |".."<font color=\""     ..Color.."\">"..Build.."</font>".."                                  ["..Ver.."]",Center = true,AutoShow = true})
local Tabs = {CombatTab = Window:AddTab('combat'),VisualsTab = Window:AddTab('visuals'),MiscellaneousTab = Window:AddTab('miscellaneous'),LocalTab = Window:AddTab('local'),WorldTab = Window:AddTab('world'),UISettings = Window:AddTab('settings')}

--// Notifications
Library:Notify(("Welcome thank you for using [BALLZ.CC] - "..game.Players.LocalPlayer.Name.." 👋"), 6)
Library:Notify(("Status: 🟢 - UD (UNV)"), 6)
local notifyPlayerChange = function(player, message, color)
local prefix = "notification - player"
Library:Notify(("%s | user: %s | %s"):format(prefix, player.DisplayName, message), 5, color)
end
game.Players.PlayerAdded:Connect(function(player)
notifyPlayerChange(player, "joined", Color3.fromRGB(255, 191, 0))
end)
game.Players.PlayerRemoving:Connect(function(player)
notifyPlayerChange(player, "left", Color3.fromRGB(255, 191, 0))
end)








local ItemConfigs = game:GetService("ReplicatedStorage").Shared.items["ranged weps"]
local Camera = game:GetService("Workspace").Camera
local Camera = game:GetService("Workspace").CurrentCamera
local Cam = game:GetService("Workspace").Camera
local CharcaterMiddle = game:GetService("Workspace").Ignore.LocalCharacter.Middle
local Mouse = game.Players.LocalPlayer:GetMouse()
local lighting = game:GetService("Lighting")
local SoundService = game:GetService("SoundService")
local Decimals = 2
local Clock = os.clock()




--










local SilentTabbox = Tabs.CombatTab:AddLeftTabbox()
local snapline = SilentTabbox:AddTab('nothing bc of lv3')
local CrosshairXTab = SilentTabbox:AddTab('')

--SnapLine Toggles--

   
-------- --------




local CrossHairX = Drawing.new("Circle"), Drawing.new("Circle")
--
CrossHairX.Position = Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
CrossHairX.Thickness = 1
CrossHairX.ZIndex = 3

do
CrosshairXTab:AddToggle('zCrosshairX_Toggle', {Text = 'enabled', Default = false}):AddColorPicker("eCrosshairX_Color", {Default = Color3.fromRGB(255, 191, 0)}):OnChanged(function()
CrossHairX.Visible = Toggles.zCrosshairX_Toggle.Value
end)

Options.eCrosshairX_Color:OnChanged(function()
CrossHairX.Color = Options.eCrosshairX_Color.Value
end)

CrosshairXTab:AddToggle('Crosshair_Filled1', {Text = 'filled', Default = false}):OnChanged(function()
CrossHairX.Filled = Toggles.Crosshair_Filled1.Value
end)

CrosshairXTab:AddSlider('Crosshair_Radius', {Text = 'size', Suffix = "°", Default = 2, Min = 0, Max = 100, Rounding = 0, Compact = true}):OnChanged(function(CrosshairXRadius)
CrossHairX.Radius = CrosshairXRadius
end)
end





--






--ESP--

local Functions = {}
local Esp = {Settings={
    Boxes=true,BoxesOutline=true,BoxesColor=Color3.fromRGB(255, 255, 255),BoxesOutlineColor=Color3.fromRGB(0,0,0),
    Sleeping=false,SleepingColor=Color3.fromRGB(255, 255, 255),
    Distances=false,DistanceColor=Color3.fromRGB(255, 255, 255),
    Armour=false,ArmourColor=Color3.fromRGB(255, 255, 255),
    Tool=false,ToolColor=Color3.fromRGB(255, 255, 255),
    ViewAngle=false,ViewAngleColor=Color3.fromRGB(255, 255, 255),ViewAngleThickness=1,ViewAngleTransparrency=1,
    TextFont=2,TextOutline=true,TextSize=15,RenderDistance=1500,TeamCheck=false,TargetSleepers=false,MinTextSize=8
},Drawings={},Connections={},Players={}}
local Fonts = {["UI"]=0,["System"]=1,["Plex"]=2,["Monospace"]=3}
local cache = {}

--Locals
local Camera = game:GetService("Workspace").CurrentCamera
local CharcaterMiddle = game:GetService("Workspace").Ignore.LocalCharacter.Middle

--Functions
function Functions:IsSleeping(Model)
    if Model and Model:FindFirstChild("AnimationController") and Model.AnimationController:FindFirstChild("Animator") then
		for i,v in pairs(Model.AnimationController.Animator:GetPlayingAnimationTracks()) do
            if v.Animation.AnimationId == "rbxassetid://13280887764" then
                return true
            else
                return false
            end
        end
    end
end
function Functions:Draw(Type,Propities)
    if not Type and not Propities then return end
    local drawing = Drawing.new(Type)
    for i,v in pairs(Propities) do
        drawing[i] = v
    end
    table.insert(Esp.Drawings,drawing)
    return drawing
end
function Esp:CreateEsp(PlayerTable)
    if not PlayerTable then return end
    local drawings = {}
    drawings.BoxOutline = Functions:Draw("Square",{Thickness=2,Filled=false,Transparency=1,Color=Esp.Settings.BoxesOutlineColor,Visible=false,ZIndex = -1,Visible=false});
    drawings.Box = Functions:Draw("Square",{Thickness=1,Filled=false,Transparency=1,Color=Esp.Settings.BoxesColor,Visible=false,ZIndex = 2,Visible=false});
    drawings.Sleeping = Functions:Draw("Text",{Text = "Nil",Font=Esp.Settings.TextFont,Size=Esp.Settings.TextSize,Center=true,Outline=Esp.Settings.TextOutline,Color = Esp.Settings.SleepingColor,ZIndex = 2,Visible=false})
    drawings.Distance = Functions:Draw("Text",{Text = "Nil",Font=Esp.Settings.TextFont,Size=Esp.Settings.TextSize,Center=true,Outline=Esp.Settings.TextOutline,Color = Esp.Settings.SleepingColor,ZIndex = 2,Visible=false})
    drawings.Armour = Functions:Draw("Text",{Text = "Naked",Font=Esp.Settings.TextFont,Size=Esp.Settings.TextSize,Center=false,Outline=Esp.Settings.TextOutline,Color = Esp.Settings.ArmourColor,ZIndex = 2,Visible=false})
    drawings.ViewAngle = Functions:Draw("Line",{Thickness=Esp.Settings.ViewAngleThickness,Transparency=Esp.Settings.ViewAngleTransparrency,Color=Esp.Settings.ViewAngleColor,ZIndex=2,Visible=false})
    drawings.PlayerTable = PlayerTable
    Esp.Players[PlayerTable.model] = drawings
end
function Esp:RemoveEsp(PlayerTable)
    if not PlayerTable and PlayerTable.model ~= nil then return end
    esp = Esp.Players[PlayerTable.model];
    if not esp then return end
    for i, v in pairs(esp) do
        if not type(v) == "table" then
            v:Remove();
        end
    end
    Esp.Players[PlayerTable.model] = nil;
end

function Esp:UpdateEsp()
    for i,v in pairs(Esp.Players) do
        local Character = i
        local Position,OnScreen = Camera:WorldToViewportPoint(Character:GetPivot().Position);
        local scale = 1 / (Position.Z * math.tan(math.rad(Camera.FieldOfView * 0.5)) * 2) * 100;
        local w,h = math.floor(40 * scale), math.floor(55 * scale);
        local x,y = math.floor(Position.X), math.floor(Position.Y);
        local Distance = (CharcaterMiddle:GetPivot().Position-Character:GetPivot().Position).Magnitude
        local BoxPosX,BoxPosY = math.floor(x - w * 0.5),math.floor(y - h * 0.5)
        local offsetCFrame = CFrame.new(0, 0, -4)
        local sleeping = Functions:IsSleeping(Character)
        if Character and Character:FindFirstChild("HumanoidRootPart") and Character:FindFirstChild("Head") then
            local TeamTag = Character.Head.Teamtag.Enabled
            if OnScreen == true and Esp.Settings.Boxes == true and Distance <= Esp.Settings.RenderDistance then
                if Esp.Settings.TeamCheck == true and TeamTag == false then 
                    v.BoxOutline.Visible = Esp.Settings.BoxesOutline;v.Box.Visible = true
                elseif Esp.Settings.TeamCheck == true and TeamTag == true then
                    v.BoxOutline.Visible = false;v.Box.Visible = false
                else
                    v.BoxOutline.Visible = Esp.Settings.BoxesOutline;v.Box.Visible = true
                end
                if Esp.Settings.TargetSleepers == true and sleeping == true then
                    v.BoxOutline.Visible = false;v.Box.Visible = false
                end
                v.BoxOutline.Position = Vector2.new(BoxPosX,BoxPosY);v.BoxOutline.Size = Vector2.new(w,h)
                v.Box.Position = Vector2.new(BoxPosX,BoxPosY);v.Box.Size = Vector2.new(w,h)
                v.Box.Color = Esp.Settings.BoxesColor;v.BoxOutline.Color = Esp.Settings.BoxesOutlineColor
            else
                v.BoxOutline.Visible = false;v.Box.Visible = false
            end
            if OnScreen == true and Esp.Settings.Sleeping == true and Distance <= Esp.Settings.RenderDistance then
                if sleeping == true then v.Sleeping.Text = "Sleeping" else v.Sleeping.Text = "Awake" end
                if Esp.Settings.TeamCheck == true and TeamTag == false then
                    v.Sleeping.Visible = true
                elseif Esp.Settings.TeamCheck == true and TeamTag == true then
                    v.Sleeping.Visible = false
                end
                if Esp.Settings.TargetSleepers == true and sleeping == true then v.Sleeping.Visible = false end

                v.Sleeping.Outline=Esp.Settings.TextOutline;v.Sleeping.Color=Esp.Settings.SleepingColor;v.Sleeping.Size=math.max(math.min(math.abs(Esp.Settings.TextSize*scale),Esp.Settings.TextSize),Esp.Settings.MinTextSize);v.Sleeping.Color = Esp.Settings.SleepingColor;v.Sleeping.Font=Esp.Settings.TextFont;v.Sleeping.Position = Vector2.new(x,math.floor(y-h*0.5-v.Sleeping.TextBounds.Y))
            else
                v.Sleeping.Visible=false
            end
            if OnScreen == true and Esp.Settings.Distances == true and Distance <= Esp.Settings.RenderDistance then
                if Esp.Settings.TeamCheck == true and TeamTag == false then
                    v.Distance.Visible = true
                elseif Esp.Settings.TeamCheck == true and TeamTag == true then
                    v.Distance.Visible = false
                end
                if Esp.Settings.TargetSleepers == true and sleeping == true then v.Distance.Visible = false end

                if Esp.Settings.Sleeping == false then
                    v.Distance.Text = math.floor(Distance).."s"
                else
                    v.Distance.Text = math.floor(Distance).."s"
                end
                v.Distance.Outline=Esp.Settings.TextOutline;v.Distance.Color=Esp.Settings.SleepingColor;v.Distance.Size=math.max(math.min(math.abs(Esp.Settings.TextSize*scale),Esp.Settings.TextSize),Esp.Settings.MinTextSize);v.Distance.Color = Esp.Settings.DistanceColor;v.Distance.Font=Esp.Settings.TextFont;v.Distance.Position = Vector2.new(x,math.floor(y+h*.5))
            else
                v.Distance.Visible = false
            end
            if OnScreen == true and Esp.Settings.Armour == true and Distance <= Esp.Settings.RenderDistance then
                if Character.Armor:FindFirstChildOfClass("Folder") then v.Armour.Text = "Armoured" else v.Armour.Text = "Naked" end
                if Esp.Settings.TeamCheck == true and TeamTag == false then v.Armour.Visible = true elseif Esp.Settings.TeamCheck == true and TeamTag == true then v.Armour.Visible = false else v.Armour.Visible = true end
                if Esp.Settings.TargetSleepers == true and sleeping == true then v.Armour.Visible = false end
                v.Armour.Outline=Esp.Settings.TextOutline;v.Armour.Size = math.max(math.min(math.abs(Esp.Settings.TextSize*scale),Esp.Settings.TextSize),Esp.Settings.MinTextSize);
                v.Armour.Position=Vector2.new(math.floor((BoxPosX+w)+v.Armour.TextBounds.X/10),BoxPosY+v.Armour.TextBounds.Y*1.55*0.5-((v.Armour.TextBounds.Y*2)*0.5));
                v.Armour.Color = Esp.Settings.ArmourColor;v.Armour.Font=Esp.Settings.TextFont
            else
                v.Armour.Visible = false
            end
            if OnScreen == true and Esp.Settings.ViewAngle == true and Distance <= Esp.Settings.RenderDistance then
                if Esp.Settings.TeamCheck == true and TeamTag == false then v.ViewAngle.Visible = true elseif Esp.Settings.TeamCheck == true and TeamTag == true then v.ViewAngle.Visible = false else v.ViewAngle.Visible = true end
                if Esp.Settings.TargetSleepers == true and sleeping == true then v.ViewAngle.Visible = false end
                v.ViewAngle.Color = Esp.Settings.ViewAngleColor;v.ViewAngle.Thickness=Esp.Settings.ViewAngleThickness;v.Transparency=Esp.Settings.ViewAngleTransparrency;
                local headpos = Camera:WorldToViewportPoint(Character.Head.Position)
                local offsetCFrame = CFrame.new(0, 0, -4)
                v.ViewAngle.From = Vector2.new(headpos.X, headpos.Y)
                local value = math.clamp(1/Distance*100, 0.1, 1)
                local dir = Character.Head.CFrame:ToWorldSpace(offsetCFrame)
                offsetCFrame = offsetCFrame * CFrame.new(0, 0, 0.4)
                local dirpos = Camera:WorldToViewportPoint(Vector3.new(dir.X, dir.Y, dir.Z))
                if OnScreen == true then
                    v.ViewAngle.To = Vector2.new(dirpos.X, dirpos.Y)
                    offsetCFrame = CFrame.new(0, 0, -4)
                end
            else
                v.ViewAngle.Visible = false
            end
        else
            v.Box.Visible=false;v.BoxOutline.Visible=false;v.Armour.Visible=false;v.Distance.Visible=false;v.ViewAngle.Visible=false;v.Sleeping.Visible=false;
        end
    end
end

--Connections
local PlayerUpdater = game:GetService("RunService").RenderStepped
local PlayerConnection = PlayerUpdater:Connect(function()
    Esp:UpdateEsp()
end)

--Init Functions
for i,v in pairs(workspace:GetChildren()) do
	if v:FindFirstChild("HumanoidRootPart") then
        table.insert(cache,v)
        Esp:CreateEsp({model=v})
	end
end

game:GetService("Workspace").ChildAdded:Connect(function(child)
    if child:FindFirstChild("HumanoidRootPart") and not table.find(cache,child) then
        table.insert(cache,child)
        Esp:CreateEsp({model=child})
    end
end)

local PlayerVisualTabbox = Tabs.VisualsTab:AddLeftTabbox()
local PlayerVisualTab = PlayerVisualTabbox:AddTab('Players')
local PlayerSettingsVisualTab = PlayerVisualTabbox:AddTab('Settings')

PlayerVisualTab:AddToggle('Boxes',{Text='Boxes',Default=false}):AddColorPicker('BoxesColor',{Default=Color3.fromRGB(255, 255, 255),Title='Color'}):AddColorPicker('BoxesOutlineColor',{Default=Color3.fromRGB(0,0,0),Title='Color'})
PlayerVisualTab:AddToggle('Distances',{Text='Distance',Default=false}):AddColorPicker('DistancesColor',{Default=Color3.fromRGB(255, 255, 255),Title='Color'})
PlayerVisualTab:AddToggle('Sleeping',{Text='Sleeping',Default=false}):AddColorPicker('SleepingColor',{Default=Color3.fromRGB(255, 255, 255),Title='Color'})
PlayerVisualTab:AddToggle('Armour',{Text='Armour',Default=false}):AddColorPicker('ArmourColor',{Default=Color3.fromRGB(255, 255, 255),Title='Color'})
PlayerVisualTab:AddToggle('ViewAngle',{Text='View Angle',Default=false}):AddColorPicker('ViewAngleColor',{Default=Color3.fromRGB(255, 255, 255),Title='Color'})

--Esp Switches
Toggles.ViewAngle:OnChanged(function(Value)
    Esp.Settings.ViewAngle = Value
end)
Options.ViewAngleColor:OnChanged(function(Value)
    Esp.Settings.ViewAngleColor = Value
end)
Toggles.Armour:OnChanged(function(Value)
    Esp.Settings.Armour = Value
end)
Options.ArmourColor:OnChanged(function(Value)
    Esp.Settings.ArmourColor = Value
end)
Toggles.Armour:OnChanged(function(Value)
    Esp.Settings.Armour = Value
end)
Toggles.Distances:OnChanged(function(Value)
    Esp.Settings.Distances = Value
end)
Options.DistancesColor:OnChanged(function(Value)
    Esp.Settings.DistanceColor = Value
end)
Options.BoxesColor:OnChanged(function(Value)
    Esp.Settings.BoxesColor = Value
end)
Options.BoxesOutlineColor:OnChanged(function(Value)
    Esp.Settings.BoxesOutlineColor = Value
end)
Toggles.Boxes:OnChanged(function(Value)
    Esp.Settings.Boxes = Value
end)
Options.SleepingColor:OnChanged(function(Value)
    Esp.Settings.SleepingColor = Value
end)
Toggles.Sleeping:OnChanged(function(Value)
    Esp.Settings.Sleeping = Value
end)
PlayerSettingsVisualTab:AddSlider('RenderDistance', {Text='Render Distance',Default=500,Min=1,Max=1500,Rounding=0,Compact=false,Suffix="s"}):OnChanged(function(Value)
    Esp.Settings.RenderDistance = Value
end)
PlayerSettingsVisualTab:AddToggle('TargetSleepers',{Text='Dont Show Sleepers',Default=true}):OnChanged(function(Value)
    Esp.Settings.TargetSleepers = Value
end)
PlayerSettingsVisualTab:AddToggle('BoxesOutlines',{Text='Box Outlines',Default=true}):OnChanged(function(Value)
    Esp.Settings.BoxesOutline = Value
end)
PlayerSettingsVisualTab:AddToggle('TeamCheck',{Text='Team Check',Default=true}):OnChanged(function(Value)
    Esp.Settings.TeamCheck = Value
end)
PlayerSettingsVisualTab:AddToggle('TextOutline',{Text='Text Outlines',Default=true}):OnChanged(function(Value)
    Esp.Settings.TextOutline = Value
end)





local HitboxOverrideTabBox = Tabs.CombatTab:AddLeftTabbox('hitbox overrider')
local HitboxOverrideTab = HitboxOverrideTabBox:AddTab('hitbox overrider')

--* Hitbox Overrider *--

local HBO2 = false
local HBO2H = 100
local HBO2P = "Head"
HitboxOverrideTab:AddToggle('',{Text='enabled',Default=false}):OnChanged(function(Value)
HBO2 = Value;
end)

HitboxOverrideTab:AddSlider('', {Text='hitchance:',Default=100,Min=0,Max=100,Rounding=0,Compact=false,Suffix="%"}):OnChanged(function(Value)
HBO2H = Value;
end)

HitboxOverrideTab:AddDropdown('', {Values = {"Head", "HumanoidRootPart", "Head", "Random"},Default = 1,Multi = false,Text = 'hitpart:'}):OnChanged(function(Value)
HBO2P = Value
end)




  
local VisualsTabBox = Tabs.VisualsTab:AddRightTabbox('crosshair')
local CrosshairXTab = VisualsTabBox:AddTab('crosshair')

--* Crosshair *--

local CrossHairX = Drawing.new("Circle"), Drawing.new("Circle")
--
CrossHairX.Position = Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
CrossHairX.Thickness = 1
CrossHairX.ZIndex = 3

do
CrosshairXTab:AddToggle('zCrosshairX_Toggle', {Text = 'enabled', Default = false}):AddColorPicker("eCrosshairX_Color", {Default = Color3.fromRGB(255, 255, 255)}):OnChanged(function()
CrossHairX.Visible = Toggles.zCrosshairX_Toggle.Value
end)

Options.eCrosshairX_Color:OnChanged(function()
CrossHairX.Color = Options.eCrosshairX_Color.Value
end)

CrosshairXTab:AddToggle('Crosshair_Filled1', {Text = 'filled', Default = false}):OnChanged(function()
CrossHairX.Filled = Toggles.Crosshair_Filled1.Value
end)

CrosshairXTab:AddSlider('Crosshair_Radius', {Text = 'size', Suffix = "°", Default = 1, Min = 0, Max = 1, Rounding = 0, Compact = true}):OnChanged(function(CrosshairXRadius)
CrossHairX.Radius = CrosshairXRadius
end)
end






local CustomHitsoundsTabBox = Tabs.MiscellaneousTab:AddLeftTabbox('custom hitsounds')
local PlayerHitsoundsTab = CustomHitsoundsTabBox:AddTab('custom hitsounds')

--* Player Hitsounds *--

SoundService.PlayerHitHeadshot.Volume = 5
SoundService.PlayerHitHeadshot.Pitch = 1
SoundService.PlayerHitHeadshot.EqualizerSoundEffect.HighGain = -1.5
local sounds = {["Defualt Headshot"] = "rbxassetid://9119561046",["Defualt Body"] = "rbxassetid://9114487369",Neverlose = "rbxassetid://8726881116",Gamesense = "rbxassetid://4817809188",One = "rbxassetid://7380502345",Bell = "rbxassetid://6534947240",Rust = "rbxassetid://1255040462",TF2 = "rbxassetid://2868331684",Slime = "rbxassetid://6916371803",["Among Us"] = "rbxassetid://5700183626",Minecraft = "rbxassetid://4018616850",["CS:GO"] = "rbxassetid://6937353691",Saber = "rbxassetid://8415678813",Baimware = "rbxassetid://3124331820",Osu = "rbxassetid://7149255551",["TF2 Critical"] = "rbxassetid://296102734",Bat = "rbxassetid://3333907347",["Call of Duty"] = "rbxassetid://5952120301",Bubble = "rbxassetid://6534947588",Pick = "rbxassetid://1347140027",Pop = "rbxassetid://198598793",Bruh = "rbxassetid://4275842574",Bamboo = "rbxassetid://3769434519",Crowbar = "rbxassetid://546410481",Weeb = "rbxassetid://6442965016",Beep = "rbxassetid://8177256015",Bambi = "rbxassetid://8437203821",Stone = "rbxassetid://3581383408",["Old Fatality"] = "rbxassetid://6607142036",Click = "rbxassetid://8053704437",Ding = "rbxassetid://7149516994",Snow = "rbxassetid://6455527632",Laser = "rbxassetid://7837461331",Mario = "rbxassetid://2815207981",Steve = "rbxassetid://4965083997"}

PlayerHitsoundsTab:AddToggle('Enabled_Toggle1', {Text = 'enabled', Default = false})

PlayerHitsoundsTab:AddDropdown('HeadshotHit', {Values = { 'Defualt Headshot','Neverlose','Gamesense','One','Bell','Rust','TF2','Slime','Among Us','Minecraft','CS:GO','Saber','Baimware','Osu','TF2 Critical','Bat','Call of Duty','Bubble','Pick','Pop','Bruh','Bamboo','Crowbar','Weeb','Beep','Bambi','Stone','Old Fatality','Click','Ding','Snow','Laser','Mario','Steve','Snowdrake' },Default = 1, Multi = false, Text = 'Head Hitsound:'})
Options.HeadshotHit:OnChanged(function()
local soundId = sounds[Options.HeadshotHit.Value]
game:GetService("SoundService").PlayerHitHeadshot.SoundId = soundId
game:GetService("SoundService").PlayerHitHeadshot.Playing = true
end)

PlayerHitsoundsTab:AddSlider('Volume_Slider', {Text = 'volume', Default = 5, Min = 0, Max = 10, Rounding = 0, Compact = true,}):OnChanged(function(vol)
SoundService.PlayerHitHeadshot.Volume = vol
end)

PlayerHitsoundsTab:AddSlider('Pitch_Slider', {Text = 'pitch', Default = 1, Min = 0, Max = 2, Rounding = 2, Compact = true,}):OnChanged(function(pich)
SoundService.PlayerHitHeadshot.Pitch = pich
end)

PlayerHitsoundsTab:AddInput('HeadShotHitAssetID', {Default = "rbxassetid://9119561046",Numeric = false,Finished = true,Text = 'custom sound:',Placeholder = "rbxassetid://9119561046",}):OnChanged(function(CustomSoundID)
SoundService.PlayerHitHeadshot.SoundId = CustomSoundID
end)
--
PlayerHitsoundsTab:AddToggle('Enabled_Toggle2', {Text = 'enabled', Default = false})

PlayerHitsoundsTab:AddDropdown('Hit', {Values = { 'Defualt Body','Neverlose','Gamesense','One','Bell','Rust','TF2','Slime','Among Us','Minecraft','CS:GO','Saber','Baimware','Osu','TF2 Critical','Bat','Call of Duty','Bubble','Pick','Pop','Bruh','Bamboo','Crowbar','Weeb','Beep','Bambi','Stone','Old Fatality','Click','Ding','Snow','Laser','Mario','Steve','Snowdrake' },Default = 1, Multi = false, Text = 'Body Hitsound:'})
Options.Hit:OnChanged(function()
local soundId = sounds[Options.Hit.Value]
game:GetService("SoundService").PlayerHit2.SoundId = soundId
game:GetService("SoundService").PlayerHit2.Playing = true
end)

PlayerHitsoundsTab:AddSlider('Volume_Slider', {Text = 'volume', Default = 5, Min = 0, Max = 10, Rounding = 0, Compact = true,}):OnChanged(function(vole)
SoundService.PlayerHit2.Volume = vole
end)

PlayerHitsoundsTab:AddSlider('Pitch_Slider', {Text = 'pitch', Default = 1, Min = 0, Max = 2, Rounding = 2, Compact = true,}):OnChanged(function(piche)
SoundService.PlayerHit2.Pitch = piche
end)

PlayerHitsoundsTab:AddInput('PlayerHitAssetID', {Default = "rbxassetid://9114487369",Numeric = false,Finished = true,Text = 'custom sound:',Placeholder = "rbxassetid://9114487369",}):OnChanged(function(CustomSoundID)
SoundService.PlayerHit2.SoundId = CustomSoundID
end)




local HudTabBox = Tabs.LocalTab:AddRightTabbox('hud')
local HudTab = HudTabBox:AddTab('hud')

--* Hud *--

HudTab:AddToggle('AWASZnfh', {Text = "remove server info",Default = false,Tooltip = "Hides Server Info",}):OnChanged(function(Chillax1)
if Chillax1 == true then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.ServerInfo.Visible = false
elseif Chillax1 == false then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.ServerInfo.Visible = true
end
end)

HudTab:AddToggle('AWAaSZasanfh', {Text = "remove server status",Default = false,Tooltip = "Hides Server Status",}):OnChanged(function(Chillax2)
if Chillax2 == true then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.ServerStatus.Visible = false
elseif Chillax2 == false then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.ServerStatus.Visible = true
end
end)

HudTab:AddToggle('GnAf', {Text = "hide chat",Default = false,Tooltip = "Hides chat )",}):OnChanged(function(HideChat)
if HideChat == true then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.Chat.Position = UDim2.new(0, 0, 1, 0)
elseif HideChat == false then
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.Chat.Position = UDim2.new(0, 0, 0, 0)
end
end)

HudTab:AddLabel('custom inventory:'):AddColorPicker('Inventory_Color', { Default = Color3.fromRGB(255, 255, 255)})
Options.Inventory_Color:OnChanged(function(Inventory_Color_Value)
local hotbar = game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.BottomCenter
for i = 26, 29 do
hotbar.Armor["ItemSlot" .. i].BackgroundColor3 = Inventory_Color_Value
end
for i = 6, 25 do
hotbar.Inventory["ItemSlot" .. i].BackgroundColor3 = Inventory_Color_Value
end
end)

HudTab:AddLabel('energy:'):AddColorPicker('Energy_Color_Value', { Default = Color3.fromRGB(255, 255, 255)})
Options.Energy_Color_Value:OnChanged(function(Energy_Color_Value)
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.Vitals.EnergyFrame.Energy.BackgroundColor3 = Energy_Color_Value
end)

HudTab:AddLabel('health:'):AddColorPicker('Health_Color_Value', { Default = Color3.fromRGB(255, 255, 255)})
Options.Health_Color_Value:OnChanged(function(Health_Color_Value)
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.Vitals.HealthFrame.Health.BackgroundColor3 = Health_Color_Value
end)

HudTab:AddLabel('ammo:'):AddColorPicker('Ammo_Color_Value', { Default = Color3.fromRGB(255, 255, 255)})
Options.Ammo_Color_Value:OnChanged(function(Ammo_Color_Value)
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.BottomCenter.Ammo.TextColor3 = Ammo_Color_Value
end)

HudTab:AddSlider('Vitals_Transparency', {Text = 'vitals transparency', Suffix = "%", Default = 10, Min = 0, Max = 100, Rounding = 0, Compact = true}):OnChanged(function(VitalsTransparency)
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.Vitals.EnergyFrame.Energy.BackgroundTransparency = VitalsTransparency / 100
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.Vitals.HealthFrame.Health.BackgroundTransparency = VitalsTransparency / 100
end)

HudTab:AddSlider('Background_Transparency', {Text = 'inventory transparency', Suffix = "%", Default = 70, Min = 0, Max = 100, Rounding = 0, Compact = true}):OnChanged(function(InventoryTransparency)
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.BottomCenter.Inventory.BackgroundTransparency = InventoryTransparency / 100
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.BottomCenter.Hotbar.BackgroundTransparency = InventoryTransparency / 100
game:GetService("Players").LocalPlayer.PlayerGui.GameUI.FPS.BottomCenter.Armor.BackgroundTransparency = InventoryTransparency / 100
end)





local HeadHitboxTabBox = Tabs.CombatTab:AddRightTabbox('hitbox expander')
local HeadHitboxTab = HeadHitboxTabBox:AddTab('hitbox expander')

--* Head Hitbox Expander *--

local hbExpander = {
HeadExtends = false,
XSize = 5,
YSize = 5,
ZSize = 5,
HitboxTransparency = 50,
}

local HedsOn = Instance.new("Part")
local HBXColor = Color3.fromRGB(255, 255, 255)
local HBXMaterial = "ForceField"
HedsOn.Name = "HedsOn"
HedsOn.Anchored = false
HedsOn.CanCollide = false
HedsOn.Transparency = hbExpander.HitboxTransparency
HedsOn.Color = HBXColor
HedsOn.Material = HBXMaterial
HedsOn.Size = Vector3.new(5, 5, 10)
HedsOn.Parent = game.ReplicatedStorage

HeadHitboxTab:AddToggle('HBO',{Text='enabled',Default=false}):AddColorPicker('HBX_Color',{Default=Color3.fromRGB(255, 255, 255),Title='Color'}):OnChanged(function(Value)
hbExpander.HeadExtends = Value
end)
Options.HBX_Color:OnChanged(function(Value)
HBXColor = Value
end)

HeadHitboxTab:AddDropdown('', {Values = {"ForceField", "Neon", "CrackedLava"}, Default = 1, Multi = false, Text = 'material:'}):OnChanged(function(Dropdown)
HBXMaterial = Dropdown
end)

HeadHitboxTab:AddSlider('HitboxXSize_Slider', {Text = 'hitbox width:', Default = 5, Min = 0, Max = 10, Rounding = 2, Suffix = "%", Compact = false}):OnChanged(function(HitboxXSize)
hbExpander.XSize = HitboxXSize
hbExpander.ZSize = HitboxXSize
end)

HeadHitboxTab:AddSlider('HitboxYSize_Slider', {Text = 'hitbox height:', Default = 5, Min = 0, Max = 10, Rounding = 2, Suffix = "%", Compact = false}):OnChanged(function(HitboxYSize)
hbExpander.YSize = HitboxYSize
hbExpander.ZSize = HitboxYSize
end)

HeadHitboxTab:AddSlider('HitboxXSize_Slider', {Text = 'transparency:', Default = 50, Min = 0, Max = 100, Rounding = 0, Suffix = "%", Compact = false}):OnChanged(function(TransparencyValue)
hbExpander.HitboxTransparency = TransparencyValue / 100
end)

task.spawn(function()
while task.wait() do
if hbExpander.HeadExtends then
	for _, i in ipairs(game:GetService("Workspace"):GetChildren()) do
		if i:FindFirstChild("HumanoidRootPart") and not i:FindFirstChild("HedsOn") then
			local BigHeadsPart = Instance.new("Part");BigHeadsPart.Name = "Head";BigHeadsPart.Anchored = false;BigHeadsPart.CanCollide = false;BigHeadsPart.Transparency = hbExpander.HitboxTransparency;BigHeadsPart.Size = Vector3.new(hbExpander.XSize, hbExpander.YSize, hbExpander.ZSize);BigHeadsPart.Material=HBXMaterial;BigHeadsPart.Color = HBXColor
			local DeletePart = Instance.new("Weld");DeletePart.Parent = BigHeadsPart;DeletePart.Name = "FAKEHEAD"
			local HeadsParts = BigHeadsPart:Clone();HeadsParts.Parent = i;HeadsParts.Orientation = i.HumanoidRootPart.Orientation
			local clonedHedsOn = HedsOn:Clone();clonedHedsOn.Parent = i
			local Headswelding = Instance.new("Weld");Headswelding.Parent = HeadsParts;Headswelding.Part0 = i.HumanoidRootPart;Headswelding.Part1 = HeadsParts
			HeadsParts.Position = Vector3.new(i.HumanoidRootPart.Position.X, i.HumanoidRootPart.Position.Y - 0.6, i.HumanoidRootPart.Position.Z)
		end
	end
else
	for _, i in ipairs(game:GetService("Workspace"):GetChildren()) do
		if i:FindFirstChild("HumanoidRootPart") and i:FindFirstChild("HedsOn") then
			i.HedsOn:Remove()
			for _, a in ipairs(i:GetChildren()) do
				if a.Name == "Head" and a:FindFirstChild("FAKEHEAD") and (not a:FindFirstChild("Nametag") or not a:FindFirstChild("Face")) then
					a:Remove()
				end
			end
		end
	end
end
end
end)






local XrayTabBox = Tabs.MiscellaneousTab:AddRightTabbox('xray')
local XrayTab = XrayTabBox:AddTab('xray')

--* X-Ray *--

local XRayEnabled = false
local CurrentSliderValue = 50
XrayTab:AddToggle('Xray', {Text = 'enabled', Default = false, Tooltip}):AddKeyPicker('XRayKey', {Default = 'Non', SyncToggleState = true, Mode = 'Toggle', Text = 'X-Ray', NoUI = true}):OnChanged(function(value)
XRayEnabled = value
if XRayEnabled then
for i,v in pairs(game:GetService("Workspace"):GetChildren()) do
if v:FindFirstChild("Hitbox") then
v.Hitbox.Transparency = CurrentSliderValue
end
end
else
for i,v in pairs(game:GetService("Workspace"):GetChildren()) do
if v:FindFirstChild("Hitbox") then
v.Hitbox.Transparency = 0
end
end
end
end)

XrayTab:AddSlider('XrayChangerSlider', {Text = 'transparency:', Suffix = "%", Default = 50, Min = 0, Max = 100, Rounding = 0, Compact = false}):OnChanged(function(Value)
CurrentSliderValue = Value / 100
if XRayEnabled then
CurrentSliderValue = Value / 100
end
end)




-------------------------------------------------------------------------------------------------
--// Visuals \\--

--
local PlayerVisualTabbox = Tabs.VisualsTab:AddLeftTabbox()
local PlayerVisualTab = PlayerVisualTabbox:AddTab('player visuals')
local PlayerSettingsTab = PlayerVisualTabbox:AddTab('player settings')

--* Player ESP *--



--> Onscreen Text
local CustomText = Drawing.new("Text")
CustomText.Visible = false
CustomText.Text = "BALLZ.CC"
CustomText.Size = 12
CustomText.Outline = true
CustomText.Center = true
CustomText.Font = 2
CustomText.Color = Color3.new(255, 255, 255)
CustomText.Position = Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 1.89)
--
PlayerVisualTab:AddToggle('12t2ta22', {Text = 'onscreen',Default = false,Tooltip = 'Onscreen Information',}):AddColorPicker('OnscreenColor', {Default = Color3.fromRGB(255, 255, 255),Title = 'Color',}):OnChanged(function(ONSCREENVALUE)
CustomText.Visible = ONSCREENVALUE
end)
Options.OnscreenColor:OnChanged(function(Color320)
CustomText.Color = Color320
end)

local fadingIn, transparency, FADE_SPEED = true, 0, 0.008
local function updateTransparency()
CustomText.Transparency = transparency
transparency = transparency + (fadingIn and FADE_SPEED or -FADE_SPEED)
if fadingIn and transparency >= 1 then
fadingIn = false
elseif not fadingIn and transparency <= 0 then
fadingIn = true
end
end
game:GetService("RunService").Heartbeat:Connect(updateTransparency)


-------------------------------------------------------------------------------------------------
--// Miscellaneous \\--

--
local ExploitsTabBox = Tabs.MiscellaneousTab:AddRightTabbox('exploits')
local ExploitsTab = ExploitsTabBox:AddTab('exploits')

--* Exploits *--










local longneck = {
LongNeckEnabled = false,
UpperLimitDefault = 3,
LowerLimitDefault = 1.75,
CurrentSliderValue = 1.75,
}

ExploitsTab:AddToggle('LongNeck', {Text = 'long neck', Default = false, Tooltip}):AddKeyPicker('LongNeckKey', {Default = 'Non', SyncToggleState = true, Mode = 'Toggle', Text = 'Long Neck', NoUI = false}):OnChanged(function(value)
longneck.LongNeckEnabled = value
if not longneck.LongNeckEnabled then
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.UpperLimit = longneck.UpperLimitDefault
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.LowerLimit = longneck.LowerLimitDefault
else
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.UpperLimit = longneck.CurrentSliderValue
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.LowerLimit = longneck.CurrentSliderValue
end
end)

ExploitsTab:AddSlider('HeightChangerSlider', {Text = 'height:', Suffix = "m", Default = 4.25, Min = 3.75, Max = 7.5, Rounding = 2, Compact = false}):OnChanged(function(Value)
longneck.CurrentSliderValue = Value
if longneck.LongNeckEnabled then
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.LowerLimit = Value
game:GetService("Workspace").Ignore.LocalCharacter.Bottom.PrismaticConstraint.UpperLimit = Value
end
end)





  
local FieldOfViewTabBox = Tabs.VisualsTab:AddRightTabbox('Field of View')
local FieldOfViewTab = FieldOfViewTabBox:AddTab('Field of View')

--Camera Tab
do
FieldOfViewTab:AddToggle('Camera_FOVToggle', {Text = 'Field of View', Default = false})
FieldOfViewTab:AddSlider('Camera_FOVValue', {Text = 'FOV: ', Default = 70, Min = 0, Max = 120, Rounding = 0, Compact = true})

Toggles.Camera_FOVToggle:OnChanged(function()
if Toggles.Camera_FOVToggle.Value then
camera.FieldOfView = Options.Camera_FOVValue.Value
else
camera.FieldOfView = 70
end
end)

Options.Camera_FOVValue:OnChanged(function()
if Toggles.Camera_FOVToggle.Value then
camera.FieldOfView = Options.Camera_FOVValue.Value
end
end)

FieldOfViewTab:AddToggle('Camera_ZoomToggle', {Text = 'Enable Zoom', Default = false}):AddKeyPicker('Camera_ZoomHolding', {Default = 'Z', SyncToggleState = false, Mode = 'Hold', Text = 'Zoom Keybind', NoUI = false,})
FieldOfViewTab:AddSlider('Camera_ZoomValue', {Text = 'Zoom FOV: ', Default = 30, Min = 0, Max = 120, Rounding = 0, Compact = true})
end

LPH_NO_VIRTUALIZE(function()
camera:GetPropertyChangedSignal("FieldOfView"):Connect(function()
if Toggles.Camera_FOVToggle.Value then
camera.FieldOfView = Options.Camera_FOVValue.Value
end

if Toggles.Camera_ZoomToggle.Value and Options.Camera_ZoomHolding:GetState() then
camera.FieldOfView = Options.Camera_ZoomValue.Value
end
end)
end)()



-------------------------------------------------------------------------------------------------
--// UI Settings \\--

--// Game
local GameID = Tabs.UISettings:AddLeftGroupbox('Game')
GameID:AddInput('GameID_Check', {Default = 'Game ID', Numeric = true, Finished = false, Text = 'Game ID:', Placeholder = 'Game ID Here'})
GameID:AddButton('Join Game', function()
game:GetService("TeleportService"):Teleport(Options.GameID_Check.Value, plr)
end)

--// Menu
local MenuGroup = Tabs.UISettings:AddRightGroupbox('Menu')

MenuGroup:AddLabel(""..game:GetService("Players").LocalPlayer.PlayerGui.GameUI.ServerInfo.Text.."", true)
local playerCountLabel = MenuGroup:AddLabel("Player Count: 0", nil, true)
local function updatePlayerCount()
local playerCount = #game:GetService("Players"):GetPlayers()
playerCountLabel:SetText("Players Online: " .. playerCount)
end
game:GetService("Players").PlayerAdded:Connect(updatePlayerCount)
game:GetService("Players").PlayerRemoving:Connect(updatePlayerCount)
updatePlayerCount()

MenuGroup:AddLabel(' Made by:<TROLLZ SKIBIDI>          </font> 👑', true)

MenuGroup:AddButton("Rejoin Server", function()
    Library:Notify("Rejoining", 30)
    wait(1)
    local ts = game:GetService("TeleportService")
    local p = game:GetService("Players").LocalPlayer
    ts:Teleport(game.PlaceId, p)
    end)

MenuGroup:AddButton('Unload Script', function() Library:Unload()
for i,v in pairs(Toggles) do
v:SetValue(false)
Library:Notify('Unloaded!', 1)
end
end)

MenuGroup:AddButton('Panic Button', function()
for i,v in pairs(Toggles) do
v:SetValue(false)
Library:Notify('Panic Button!', 1)
end
end)

MenuGroup:AddButton('Copy Discord', function()
if pcall(setclipboard,"AINT SHIT NIGGA") then
Library:Notify('Successfully copied discord link to your clipboard!', 5)
end
end)

MenuGroup:AddToggle('WatermarkToggle', { Text = 'Watermark', Default = false, Tooltip = nil })
Toggles.WatermarkToggle:OnChanged(function()
while Toggles.WatermarkToggle.Value do
task.wait(1)
local fps = string.format('%.0f', game.Stats.Workspace.Heartbeat:GetValue())
local ping = string.format('%.0f', game.Stats.Network.ServerStatsItem["Data Ping"]:GetValue())
Library:SetWatermark('BALLZ.CC - FPS: ' .. fps .. ' | Ping: ' .. ping .. ' | [trident survival]')
Library:SetWatermarkVisibility(true)
end
Library:SetWatermarkVisibility(false)
end)

MenuGroup:AddToggle('UISettings_KeybindFrameVisibility', {Text = 'Keybind', Default = true}):OnChanged(function()
Library.KeybindFrame.Visible = Toggles.UISettings_KeybindFrameVisibility.Value
end)

MenuGroup:AddLabel('Menu Keybind'):AddKeyPicker('MeStarybind', { Default = 'Insert', NoUI = true, Text = 'Menu keybind' })
Library.ToggleKeybind = Options.MeStarybind

--// Manager
SaveManager:SetLibrary(Library)
SaveManager:SetFolder('BALLZ.CC/folder')
SaveManager:BuildConfigSection(Tabs.UISettings)
SaveManager:IgnoreThemeSettings()
ThemeManager:SetLibrary(Library)
ThemeManager:SetFolder('BALLZ.CC/themes')
ThemeManager:ApplyToTab(Tabs.UISettings)

--// Script Loaded
local Time = (string.format("%."..tostring(Decimals).."f", os.clock() - Clock))
Library:Notify(("Script [Loaded] In - "..tostring(Time).."s"), 15)

--Wrapping function - needed to unload(Keep at end of script)
loadstring(game:HttpGet('https://raw.githubusercontent.com/EIOlmqV6v1owgJBEoqj5lK9p01SFE2THpxcOnvX/LinoriaBurnEdition/main/LoaderManager.lua'))

local VelocityText = Drawing.new("Text")
VelocityText.Visible = true
VelocityText.Position = Vector2.new(Camera.ViewportSize.X - 120, 0)
VelocityText.Size = 15
VelocityText.Color = Color3.fromRGB(255, 191, 0)
VelocityText.Outline = true
VelocityText.Center = true
local function getTimeOfDay()
	local time = game.Lighting:GetMinutesAfterMidnight()
	local hours = math.floor(time / 60)
	local minutes = time % 60
	local timeString = string.format("%02d:%02d", hours, minutes)
	if hours >= 6 and hours < 20 then
		timeString = timeString .. " [Day]"
	else
		timeString = timeString .. " [Night]"
	end
	return "Time of Day: " .. timeString
end
while true do
	VelocityText.Text = "BALLZ.CC | Insert to Open/Close\n" .. getTimeOfDay()
	wait(1)
end
