//UWoWCore
//Throne of Thunder

#include "NewScriptPCH.h"
#include "VMapFactory.h"
#include "throne_of_thunder.h"

class instance_throne_of_thunder : public InstanceMapScript
{
public:
    instance_throne_of_thunder() : InstanceMapScript("instance_throne_of_thunder", 1098) { }

    struct instance_throne_of_thunder_InstanceMapScript : public InstanceScript
    {
        instance_throne_of_thunder_InstanceMapScript(Map* map) : InstanceScript(map) {}
        
        //GameObjects
        uint64 jinrokhpredoorGuid;
        uint64 jinrokhentdoorGuid;
        uint64 mogufont_sr_Guid;
        uint64 mogufont_nr_Guid;
        uint64 mogufont_nl_Guid;
        uint64 mogufont_sl_Guid;
        uint64 jinrokhexdoorGuid;
        uint64 horridonpredoorGuid;
        uint64 horridonentdoorGuid;
        uint64 horridonexdoorGuid;
        uint64 councilexdoorGuid;
        
        //Creature
        uint64 stormcallerGuid;
        uint64 jinrokhGuid;
        uint64 stormbringerGuid;
        uint64 horridonGuid;
        uint64 jalakGuid;
        uint64 mallakGuid;
        uint64 marliGuid;
        uint64 kazrajinGuid;
        uint64 sulGuid;
        uint64 tortosGuid;
        uint64 flameheadGuid;
        uint64 frozenheadGuid;
        uint64 venousheadGuid;
        uint64 jikunGuid;
        uint64 durumuGuid;
        uint64 primordiusGuid;
        uint64 darkanimusGuid;
        uint64 ironqonGuid;
        uint64 sulinGuid;
        uint64 lulinGuid;
        uint64 leishenGuid;
        uint64 radenGuid;

        std::vector <uint64> councilGuids;
        std::vector <uint64> mogufontsGuids;
        std::vector <uint64> councilentdoorGuids;
        
        void Initialize()
        {
            SetBossNumber(14);

            //GameObject
            jinrokhentdoorGuid  = 0;
            mogufont_sr_Guid    = 0;
            mogufont_nr_Guid    = 0;
            mogufont_nl_Guid    = 0;
            mogufont_sl_Guid    = 0;
            jinrokhexdoorGuid   = 0;
            horridonpredoorGuid = 0;
            horridonentdoorGuid = 0;
            horridonexdoorGuid  = 0;
            councilexdoorGuid   = 0;
           
            //Creature
            stormcallerGuid     = 0;
            jinrokhGuid         = 0;
            stormbringerGuid    = 0;
            horridonGuid        = 0;
            jalakGuid           = 0;
            mallakGuid          = 0;
            marliGuid           = 0;
            kazrajinGuid        = 0;
            sulGuid             = 0;
            tortosGuid          = 0;
            flameheadGuid       = 0;
            frozenheadGuid      = 0;
            venousheadGuid      = 0;
            jikunGuid           = 0;
            durumuGuid          = 0;
            primordiusGuid      = 0;
            darkanimusGuid      = 0;
            ironqonGuid         = 0;
            sulinGuid           = 0;
            lulinGuid           = 0;
            leishenGuid         = 0;
            radenGuid           = 0;

            councilGuids.clear();
            mogufontsGuids.clear();
            councilentdoorGuids.clear();
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_STORM_CALLER:
                stormcallerGuid = creature->GetGUID();
                break;
            case NPC_JINROKH:
                jinrokhGuid = creature->GetGUID();
                break;
            case NPC_STORMBRINGER:
                stormbringerGuid = creature->GetGUID();
                break;
            case NPC_HORRIDON: 
                horridonGuid = creature->GetGUID();
                break;
            case NPC_JALAK:
                jalakGuid = creature->GetGUID();
                break;
            //Council of Elders
            case NPC_FROST_KING_MALAKK:
                mallakGuid = creature->GetGUID();
                councilGuids.push_back(creature->GetGUID());
                break;
            case NPC_PRINCESS_MARLI:
                marliGuid = creature->GetGUID();
                councilGuids.push_back(creature->GetGUID());
                break;  
            case NPC_KAZRAJIN:  
                kazrajinGuid = creature->GetGUID();
                councilGuids.push_back(creature->GetGUID());
                break;
            case NPC_SUL_SANDCRAWLER: 
                sulGuid = creature->GetGUID();
                councilGuids.push_back(creature->GetGUID());
                break;
            //
            case NPC_TORTOS: 
                tortosGuid = creature->GetGUID();
                break;
            //Megaera
            case NPC_FLAMING_HEAD: 
                flameheadGuid = creature->GetGUID();
                break;
            case NPC_FROZEN_HEAD:
                frozenheadGuid = creature->GetGUID();
                break;
            case NPC_VENOMOUS_HEAD:
                venousheadGuid = creature->GetGUID();
                break;
            //
            case NPC_JI_KUN:  
                jikunGuid = creature->GetGUID();
                break;
            case NPC_DURUMU:  
                durumuGuid = creature->GetGUID();
                break;
            case NPC_PRIMORDIUS: 
                primordiusGuid = creature->GetGUID();
                break;
            case NPC_DARK_ANIMUS:  
                darkanimusGuid = creature->GetGUID();
                break;
            case NPC_IRON_QON:
                ironqonGuid = creature->GetGUID();
                break;
            //Twin consorts
            case NPC_SULIN:   
                sulinGuid = creature->GetGUID();
                break;
            case NPC_LULIN: 
                lulinGuid = creature->GetGUID();
                break;
            //
            case NPC_LEI_SHEN:
                leishenGuid = creature->GetGUID();
                break;
            case NPC_RA_DEN:
                radenGuid = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {    
            switch (go->GetEntry())
            {
            case GO_JINROKH_PRE_DOOR:
                jinrokhpredoorGuid = go->GetGUID();
                break;
            case GO_JINROKH_ENT_DOOR:
                jinrokhentdoorGuid = go->GetGUID();
                break;
            //Mogu Fonts
            case GO_MOGU_SR:
                mogufont_sr_Guid = go->GetGUID();
                mogufontsGuids.push_back(go->GetGUID());
                break;
            case GO_MOGU_NR:
                mogufont_nr_Guid = go->GetGUID();
                mogufontsGuids.push_back(go->GetGUID());
                break;
            case GO_MOGU_NL:
                mogufont_nl_Guid = go->GetGUID();
                mogufontsGuids.push_back(go->GetGUID());
                break;
            case GO_MOGU_SL:
                mogufont_sl_Guid = go->GetGUID();
                mogufontsGuids.push_back(go->GetGUID());
                break;
            //
            case GO_JINROKH_EX_DOOR:
                jinrokhexdoorGuid = go->GetGUID();
                break;
            case GO_HORRIDON_PRE_DOOR:
                horridonpredoorGuid = go->GetGUID();
                break;
            case GO_HORRIDON_ENT_DOOR:
                horridonentdoorGuid = go->GetGUID();
                break;
            case GO_HORRIDON_EX_DOOR:
                horridonexdoorGuid = go->GetGUID();
                break;
            case GO_COUNCIL_LENT_DOOR:
                councilentdoorGuids.push_back(go->GetGUID());
                break;
            case GO_COUNCIL_RENT_DOOR:
                councilentdoorGuids.push_back(go->GetGUID());
                break;
            case GO_COUNCIL_EX_DOOR:
                councilexdoorGuid = go->GetGUID();
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
            case DATA_JINROKH:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (std::vector<uint64>::const_iterator guid = mogufontsGuids.begin(); guid != mogufontsGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        HandleGameObject(jinrokhentdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(jinrokhentdoorGuid, false);
                        break;
                    case DONE:
                        HandleGameObject(jinrokhentdoorGuid, true);
                        HandleGameObject(jinrokhexdoorGuid, true); 
                        break;
                    }
                }
                break;
            case DATA_HORRIDON:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(horridonentdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(horridonentdoorGuid, false);
                        break;
                    case DONE:
                        HandleGameObject(horridonentdoorGuid, true);
                        HandleGameObject(horridonexdoorGuid, true);
                        break;
                    }
                }
                break;
            case DATA_COUNCIL_OF_ELDERS:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        //Reset all council
                        for (std::vector<uint64>::const_iterator guid = councilGuids.begin(); guid != councilGuids.end(); guid++)
                        {
                            if (Creature* council = instance->GetCreature(*guid))
                            {
                                if (council->isAlive() && council->isInCombat())
                                    council->AI()->EnterEvadeMode();
                                else if (!council->isAlive())
                                {
                                    council->Respawn();
                                    council->GetMotionMaster()->MoveTargetedHome();
                                }
                                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);
                            }
                        }

                        for (std::vector <uint64>::const_iterator guids = councilentdoorGuids.begin(); guids != councilentdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        break;
                    case IN_PROGRESS:
                        //Call all council 
                        for (std::vector<uint64>::const_iterator guid = councilGuids.begin(); guid != councilGuids.end(); guid++)
                        {
                            if (Creature* council = instance->GetCreature(*guid))
                            {
                                if (council->isAlive() && !council->isInCombat())
                                    council->AI()->DoZoneInCombat(council, 150.0f);
                                SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, council);
                            }
                        }

                        for (std::vector <uint64>::const_iterator guids = councilentdoorGuids.begin(); guids != councilentdoorGuids.end(); guids++)
                            HandleGameObject(*guids, false);
                        break;
                    case DONE:
                        for (std::vector <uint64>::const_iterator guids = councilentdoorGuids.begin(); guids != councilentdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        //HandleGameObject(councilexdoorGuid, true);
                        break;
                    }
                }
                break;
            default:
                break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data){}

        uint32 GetData(uint32 type)
        {
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
            case NPC_JINROKH:
                return jinrokhGuid;
            case NPC_HORRIDON: 
                return horridonGuid;
            case NPC_JALAK:
                return jalakGuid;
            //Council of Elders
            case NPC_FROST_KING_MALAKK:
                return mallakGuid;
            case NPC_PRINCESS_MARLI:
                return marliGuid;
            case NPC_KAZRAJIN:  
                return kazrajinGuid;
            case NPC_SUL_SANDCRAWLER: 
                return sulGuid;
            //
            case NPC_TORTOS: 
                return tortosGuid;
            //Megaera
            case NPC_FLAMING_HEAD: 
                return flameheadGuid;
            case NPC_FROZEN_HEAD:
                return frozenheadGuid;
            case NPC_VENOMOUS_HEAD:
                return venousheadGuid;
            //
            case NPC_JI_KUN:  
                return jikunGuid;
            case NPC_DURUMU:  
                return durumuGuid;
            case NPC_PRIMORDIUS: 
                return primordiusGuid;
            case NPC_DARK_ANIMUS:  
                return darkanimusGuid;
            case NPC_IRON_QON:
                return ironqonGuid;
            //Twin consorts
            case NPC_SULIN:   
                return sulinGuid;
            case NPC_LULIN: 
                return lulinGuid;
            //
            case NPC_LEI_SHEN:
                return leishenGuid;
            case NPC_RA_DEN:
                return radenGuid;
            }
            return 0;
        }

        void OnUnitDeath(Unit* who)
        {
            if (who->ToCreature())
            {
                switch (who->GetEntry())
                {
                case NPC_STORM_CALLER:
                    HandleGameObject(jinrokhpredoorGuid, true);
                    break;
                case NPC_STORMBRINGER:
                    HandleGameObject(horridonpredoorGuid, true);
                    break;
                default:
                    break;
                }
            }
        }
        
        bool IsWipe()
        {
            Map::PlayerList const& PlayerList = instance->GetPlayers();

            if (PlayerList.isEmpty())
                return true;

            for (Map::PlayerList::const_iterator Itr = PlayerList.begin(); Itr != PlayerList.end(); ++Itr)
            {
                Player* player = Itr->getSource();

                if (!player)
                    continue;

                if (player->isAlive() && !player->isGameMaster() && !player->HasAura(115877)) // Aura 115877 = Totaly Petrified
                    return false;
            }

            return true;
        }

        std::string GetSaveData()
        {
            std::ostringstream saveStream;
            saveStream << GetBossSaveData() << " ";
            return saveStream.str();
        }

        void Load(const char* data)
        {
            std::istringstream loadStream(LoadBossState(data));
            uint32 buff;
            for (uint32 i = 0; i < 14; ++i)
                loadStream >> buff;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_throne_of_thunder_InstanceMapScript(map);
    }
};

enum sSpells
{
    SPELL_STORM_WEAPON   = 139319,
    SPELL_STORM_ENERGY   = 139322,
    SPELL_CHAIN_LIGHTNIG = 139903,
    SPELL_STORMCLOUD     = 139900,
};

enum sEvent
{
    EVENT_STORM_ENERGY   = 1,
    EVENT_CHAIN_LIGHTNIG = 2,
};

//Mini boss, guard Jinrokh entrance
class npc_storm_caller : public CreatureScript
{
    public:
        npc_storm_caller() : CreatureScript("npc_storm_caller") { }
        
        struct npc_storm_callerAI : public CreatureAI
        {
            npc_storm_callerAI(Creature* pCreature) : CreatureAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }
            
            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                me->RemoveAurasDueToSpell(SPELL_STORM_WEAPON);
                events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                DoZoneInCombat(me, 100.0f);
                me->AddAura(SPELL_STORM_WEAPON, me);
                events.ScheduleEvent(EVENT_STORM_ENERGY, urand(15000, 20000));
            }
            
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_STORM_ENERGY)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(target, SPELL_STORM_ENERGY);
                        events.ScheduleEvent(EVENT_STORM_ENERGY, urand(15000, 20000));
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_storm_callerAI(pCreature);
        }
};

//Mini boss, guard Horridon entrance
class npc_stormbringer : public CreatureScript
{
    public:
        npc_stormbringer() : CreatureScript("npc_stormbringer") { }
        
        struct npc_stormbringerAI : public CreatureAI
        {
            npc_stormbringerAI(Creature* pCreature) : CreatureAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }
            
            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                me->RemoveAurasDueToSpell(SPELL_STORMCLOUD);
                events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                DoZoneInCombat(me, 100.0f);
                DoCast(me, SPELL_STORMCLOUD);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNIG, urand(15000, 20000));
            }
            
            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHAIN_LIGHTNIG)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(target, SPELL_CHAIN_LIGHTNIG);
                        events.ScheduleEvent(EVENT_STORM_ENERGY, urand(15000, 20000));
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_stormbringerAI(pCreature);
        }
};

void AddSC_instance_throne_of_thunder()
{
    new instance_throne_of_thunder();
    new npc_storm_caller();
    new npc_stormbringer();
}