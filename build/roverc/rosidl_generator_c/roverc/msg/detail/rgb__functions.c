// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roverc:msg/RGB.idl
// generated code does not contain a copyright notice
#include "roverc/msg/detail/rgb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
roverc__msg__RGB__init(roverc__msg__RGB * msg)
{
  if (!msg) {
    return false;
  }
  // red
  // green
  // blue
  return true;
}

void
roverc__msg__RGB__fini(roverc__msg__RGB * msg)
{
  if (!msg) {
    return;
  }
  // red
  // green
  // blue
}

bool
roverc__msg__RGB__are_equal(const roverc__msg__RGB * lhs, const roverc__msg__RGB * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red
  if (lhs->red != rhs->red) {
    return false;
  }
  // green
  if (lhs->green != rhs->green) {
    return false;
  }
  // blue
  if (lhs->blue != rhs->blue) {
    return false;
  }
  return true;
}

bool
roverc__msg__RGB__copy(
  const roverc__msg__RGB * input,
  roverc__msg__RGB * output)
{
  if (!input || !output) {
    return false;
  }
  // red
  output->red = input->red;
  // green
  output->green = input->green;
  // blue
  output->blue = input->blue;
  return true;
}

roverc__msg__RGB *
roverc__msg__RGB__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__RGB * msg = (roverc__msg__RGB *)allocator.allocate(sizeof(roverc__msg__RGB), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roverc__msg__RGB));
  bool success = roverc__msg__RGB__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roverc__msg__RGB__destroy(roverc__msg__RGB * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roverc__msg__RGB__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roverc__msg__RGB__Sequence__init(roverc__msg__RGB__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__RGB * data = NULL;

  if (size) {
    data = (roverc__msg__RGB *)allocator.zero_allocate(size, sizeof(roverc__msg__RGB), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roverc__msg__RGB__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roverc__msg__RGB__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
roverc__msg__RGB__Sequence__fini(roverc__msg__RGB__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roverc__msg__RGB__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

roverc__msg__RGB__Sequence *
roverc__msg__RGB__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__RGB__Sequence * array = (roverc__msg__RGB__Sequence *)allocator.allocate(sizeof(roverc__msg__RGB__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roverc__msg__RGB__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roverc__msg__RGB__Sequence__destroy(roverc__msg__RGB__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roverc__msg__RGB__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roverc__msg__RGB__Sequence__are_equal(const roverc__msg__RGB__Sequence * lhs, const roverc__msg__RGB__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roverc__msg__RGB__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roverc__msg__RGB__Sequence__copy(
  const roverc__msg__RGB__Sequence * input,
  roverc__msg__RGB__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roverc__msg__RGB);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roverc__msg__RGB * data =
      (roverc__msg__RGB *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roverc__msg__RGB__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roverc__msg__RGB__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roverc__msg__RGB__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
