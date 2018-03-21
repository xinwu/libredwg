#define DWG_TYPE DWG_TYPE_DIMENSION_ORDINATE
#include "common.c"

void
low_level_process(dwg_object *obj)
{
  dwg_ent_dim_ordinate *dim_ordinate = dwg_object_to_DIMENSION_ORDINATE(obj);

  printf("horiz dir of dim_ordinate : %f\n",
          dim_ordinate->horiz_dir);
  printf("lspace factor of dim_ordinate : %f\n", 
          dim_ordinate->lspace_factor);
  printf("lspace style of dim_ordinate : " FORMAT_BS "\n",
          dim_ordinate->lspace_style);
  printf("attach point of dim_ordinate : " FORMAT_BS "\n",
          dim_ordinate->attachment_point);
  printf("Radius of dim_ordinate : %f\n",
          dim_ordinate->elevation.ecs_11);
  printf("Thickness of dim_ordinate : %f\n",
          dim_ordinate->elevation.ecs_12);
  printf("extrusion of dim_ordinate : x = %f, y = %f, z = %f\n",
          dim_ordinate->extrusion.x, dim_ordinate->extrusion.y,
          dim_ordinate->extrusion.z);
  printf("ins_scale of dim_ordinate : x = %f, y = %f, z = %f\n",
          dim_ordinate->ins_scale.x, dim_ordinate->ins_scale.y,
          dim_ordinate->ins_scale.z);
  printf("pt10 of dim_ordinate : x = %f, y = %f, z = %f\n",
          dim_ordinate->_10_pt.x, dim_ordinate->_10_pt.y,
          dim_ordinate->_10_pt.z);
  printf("pt13 of dim_ordinate : x = %f, y = %f, z = %f\n",
          dim_ordinate->_13_pt.x, dim_ordinate->_13_pt.y,
          dim_ordinate->_13_pt.z);
  printf("pt14 of dim_ordinate : x = %f, y = %f, z = %f\n",
          dim_ordinate->_14_pt.x, dim_ordinate->_14_pt.y,
          dim_ordinate->_14_pt.z);
  printf("pt12 of dim_ordinate : x = %f, y = %f\n",
          dim_ordinate->_12_pt.x, dim_ordinate->_12_pt.y);
  printf("text_mid_pt of dim_ordinate : x = %f, y = %f\n",
          dim_ordinate->text_midpt.x, dim_ordinate->text_midpt.y);
  printf("user text of dim_ordinate : %s\n", dim_ordinate->user_text);
  printf("text rotation of dim_ordinate : %f\n", dim_ordinate->text_rot);
  printf("ins rotation of dim_ordinate : %f\n", dim_ordinate->ins_rotation);
  printf("arrow1 of dim_ordinate : " FORMAT_B "\n", dim_ordinate->flip_arrow1);
  printf("arrow2 of dim_ordinate : " FORMAT_B "\n", dim_ordinate->flip_arrow2);
  printf("flags1 of dim_ordinate : " FORMAT_RC "\n", dim_ordinate->flags_1);
  printf("flags2 of dim_ordinate : " FORMAT_RC "\n", dim_ordinate->flags_2);
  printf("act_measurement of dim_ordinate : %f\n",
          dim_ordinate->act_measurement);

}

void
api_process(dwg_object *obj)
{
  int error;
  double ecs11, ecs12, act_measure, horiz_dir, lspace_factor, text_rot, 
    ins_rot;
  BITCODE_B flip_arrow1, flip_arrow2;
  BITCODE_RC flags1, flags2;
  BITCODE_BS lspace_style, attach_pt;
  char * user_text;
  dwg_point_2d text_mid_pt, pt12;
  dwg_point_3d pt10, pt13, pt14, ext, ins_scale;

  dwg_ent_dim_ordinate *dim_ordinate = dwg_object_to_DIMENSION_ORDINATE(obj);

  horiz_dir = dwg_ent_dim_ordinate_get_horiz_dir(dim_ordinate, &error);
  if ( !error )
    printf("horiz dir of dim_ordinate : %f\n", horiz_dir);
  else
    printf("error in reading horiz dir \n");

  lspace_factor = dwg_ent_dim_ordinate_get_elevation_ecs11(dim_ordinate, 
                                                           &error);
  if ( !error )
    printf("lspace factor of dim_ordinate : %f\n", lspace_factor);
  else	
    printf("error in reading lspace factor \n");


  lspace_style = dwg_ent_dim_ordinate_get_elevation_ecs11(dim_ordinate, 
                                                          &error);
  if ( !error )
    printf("lspace style of dim_ordinate : " FORMAT_BS "\n", lspace_style);
  else
    printf("error in reading lspace style \n");

  attach_pt = dwg_ent_dim_ordinate_get_elevation_ecs11(dim_ordinate, 
                                                       &error);
  if ( !error )
    printf("attach point of dim_ordinate : " FORMAT_BS "\n", attach_pt);
  else
    printf("error in reading attach point \n");

  ecs11 = dwg_ent_dim_ordinate_get_elevation_ecs11(dim_ordinate, &error);
  if ( !error )
    printf("Radius of dim_ordinate : %f\n", ecs11);
  else
    printf("error in reading ecs11 \n");


  ecs12 = dwg_ent_dim_ordinate_get_elevation_ecs12(dim_ordinate, &error);
  if ( !error )
    printf("Thickness of dim_ordinate : %f\n",ecs12);
  else
    printf("error in reading ecs12 \n");

  dwg_ent_dim_ordinate_get_extrusion(dim_ordinate, &ext,
                                     &error);
  if ( !error )
    printf("extrusion of dim_ordinate : x = %f, y = %f, z = %f\n",
           ext.x, ext.y, ext.z);
  else
    printf("error in reading extrusion \n");

  dwg_ent_dim_ordinate_get_ins_scale(dim_ordinate, &ins_scale,
                                     &error);
  if ( !error )
    printf("ins_scale of dim_ordinate : x = %f, y = %f, z = %f\n",
           ins_scale.x, ins_scale.y, ins_scale.z);
  else
    printf("error in reading ins_scale \n");

  dwg_ent_dim_ordinate_get_10_pt(dim_ordinate, &pt10,
                                 &error);
  if ( !error )
    printf("pt10 of dim_ordinate : x = %f, y = %f, z = %f\n",
           pt10.x, pt10.y, pt10.z);
  else
    printf("error in reading pt10 \n");

  dwg_ent_dim_ordinate_get_13_pt(dim_ordinate, &pt13,
                                 &error);
  if ( !error )
    printf("pt13 of dim_ordinate : x = %f, y = %f, z = %f\n",
           pt13.x, pt13.y, pt13.z);
  else
    printf("error in reading pt13 \n");

  dwg_ent_dim_ordinate_get_14_pt(dim_ordinate, &pt14,
                                 &error);
  if ( !error )
    printf("pt14 of dim_ordinate : x = %f, y = %f, z = %f\n",
           pt14.x, pt14.y, pt14.z);
  else
    printf("error in reading pt14 \n");

  dwg_ent_dim_ordinate_get_12_pt(dim_ordinate, &pt12,
                                 &error);
  if ( !error )
    printf("pt12 of dim_ordinate : x = %f, y = %f\n",
           pt12.x, pt12.y);
  else
    printf("error in reading pt12 \n");

  dwg_ent_dim_ordinate_get_text_mid_pt(dim_ordinate, &text_mid_pt,
                                       &error);
  if ( !error )
    printf("text_mid_pt of dim_ordinate : x = %f, y = %f\n",
           text_mid_pt.x, text_mid_pt.y);
  else
    printf("error in reading text_mid_pt \n");

  user_text = dwg_ent_dim_ordinate_get_user_text(dim_ordinate, &error);
  if ( !error )
    printf("user text of dim_ordinate : %s\n", user_text);
  else
    printf("error in reading user_text \n");

  text_rot = dwg_ent_dim_ordinate_get_text_rot(dim_ordinate, &error);
  if ( !error )
    printf(" text rotation of dim_ordinate : %f\n", text_rot);
  else
    printf("in reading text rotation \n");

  ins_rot = dwg_ent_dim_ordinate_get_ins_rotation(dim_ordinate, &error);
  if ( !error )
    printf("ins rotation of dim_ordinate : %f\n", ins_rot);
  else
    printf("in reading ins rotation \n");

  flip_arrow1 = dwg_ent_dim_ordinate_get_flip_arrow1(dim_ordinate,
                                                     &error);
  if ( !error )
    printf("arrow1 of dim_ordinate : " FORMAT_B "\n", flip_arrow1);
  else
    printf("in reading arrow1 \n");

  flip_arrow2 = dwg_ent_dim_ordinate_get_flip_arrow2(dim_ordinate,
                                                     &error);
  if ( !error )
    printf("arrow1 of dim_ordinate : " FORMAT_B "\n", flip_arrow2);
  else
    printf("in reading arrow1 \n");

  flags1 = dwg_ent_dim_ordinate_get_flags1(dim_ordinate,
                                           &error);
  if ( !error )
    printf("flags1 of dim_ordinate : " FORMAT_RC "\n", flags1);
  else
    printf("in reading flags1 \n");

  flags2 = dwg_ent_dim_ordinate_get_flags2(dim_ordinate,
                                           &error);
  if ( !error )
    printf("flags2 of dim_ordinate : " FORMAT_RC "\n", flags2);
  else
    printf("in reading flags2 \n");

  act_measure = dwg_ent_dim_ordinate_get_act_measurement(dim_ordinate,
                                                         &error);
  if ( !error )
    printf("act_measurement of dim_ordinate : %f\n", act_measure);
  else
    printf("in reading act_measurement \n");
 
}